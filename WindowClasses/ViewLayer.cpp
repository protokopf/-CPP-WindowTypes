#include "ViewLayer.h"


namespace myconsolewindows
{
	ViewLayer::ViewLayer()
	{
		mCreatorManager = new WindowCreatorManager();

		SetUpConsole();
		SetUpCreator();
		SetUpWindows();

		mWindowsManager = new WindowsManager(mActiveWindow,allWindows);
		mDrawManager = new WindowDrawManager(allWindows);
		mCommandManager = new CommandManager(allWindows);

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

		RecursiveAddingWindows(mActiveWindow);
	}

	void ViewLayer::RecursiveAddingWindows(BasicWindow* root)
	{
		allWindows.push_back(root);
		if (root->GetChilds())
			for (auto child : (*root->GetChilds()))
				RecursiveAddingWindows(child);
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