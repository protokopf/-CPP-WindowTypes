#include "ViewLayer.h"


namespace myconsolewindows
{
	ViewLayer::ViewLayer()
	{
		mAllWindows = new vector<BasicWindow*>();
		mCreatorManager = new WindowCreatorManager();

		SetUpConsole();
		SetUpCreator();
		SetUpWindows();

		mWindowsManager = new WindowsManager(mActiveWindow, mAllWindows);
		mDrawManager = new WindowDrawManager(mAllWindows);
		mCommandManager = new CommandManager(mAllWindows);

		//mInputManager = new BasicKeyboardInputManager(mActiveWindow);
		mInputManager = new MouseKeyboardInputManager(mActiveWindow);
	}

	void ViewLayer::SetUpConsole()
	{
		mConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cci;
		cci.dwSize = 100;
		cci.bVisible = false;
		SetConsoleCursorInfo(mConsoleHandle, &cci);
	}
	void ViewLayer::SetUpCreator()
	{
		mCreatorManager->RegisternWindow(L"PluralWindow", CreatePluralWindow);
		// регистрация других окон по мере добавления новых окон
	}
	void ViewLayer::SetUpWindows()
	{
		BasicWindow* mainWindow = mCreatorManager->CreateMyWindow(L"PluralWindow", mActiveWindow, L"MainWindow", 0, 0, 79, 24, mConsoleHandle);
		mainWindow->AddChildWindow(mCreatorManager->CreateMyWindow(L"PluralWindow", mActiveWindow, L"Child1", 5, 5, 15, 5, mConsoleHandle));
		mainWindow->AddChildWindow(mCreatorManager->CreateMyWindow(L"PluralWindow", mActiveWindow, L"Child2", 30, 10, 4, 4, mConsoleHandle));
		mainWindow->AddChildWindow(mCreatorManager->CreateMyWindow(L"PluralWindow", mActiveWindow, L"Child3", 50, 5, 3, 4, mConsoleHandle));
		
		if ((mActiveWindow = mainWindow)->GetChilds())
			(*mActiveWindow->GetChilds())[0]->InFocus();
	}


	void ViewLayer::MainLoop()
	{
		mDrawManager->InitDraw();
		while (true)
		{
			if (mInputManager->Check())
				mCommandManager->ExecuteCommands();
			mDrawManager->DrawWindows();
		}
	}

	ViewLayer::~ViewLayer()
	{
		delete mCreatorManager;
		delete mWindowsManager;
		delete mInputManager;
		delete mCommandManager;
		delete mDrawManager;
	}
}