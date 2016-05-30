#include "ViewLayer.h"


namespace myconsolewindows
{
	ViewLayer::ViewLayer()
	{
		mCreatorManager = new WindowCreatorManager();
		SetUpCreator();

		// создание окон

		mWindowsManager = new WindowsManager(mActiveWindow,allWindows);
		mDrawManager = new WindowDrawManager(mActiveWindow, allWindows);

		mInputManager = new BasicKeyboardInputManager(mActiveWindow);
		mCommandManager = new CommandManager(mActiveWindow);
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
		mCreatorManager->RegisternWindow("PluralWindow", CreatePluralWindow);
		// регистрация других окон по мере добавления новых окон
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