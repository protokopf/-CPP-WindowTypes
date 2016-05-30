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

		mInputManager = new BasicKeyboardInputManager(mActiveWindow);
		
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
		mainWindow->AddChildWindow(mCreatorManager->CreateMyWindow(L"PluralWindow", mActiveWindow, L"Child1", 12, 12, 10, 10, mConsoleHandle));
		mActiveWindow = mainWindow;
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