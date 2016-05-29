#include "ViewLayer.h"


namespace myconsolewindows
{
	ViewLayer::ViewLayer()
	{
		mCreatorManager = new WindowCreatorManager();
		SetUpCreator();


		// создание окон
		
		mDrawManager = new WindowDrawManager();
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
		mCreatorManager->RegisternWindow("PluralWindow", CreatePluralWindow);
		// регистрация других окон по мере добавления новых окон
	}

	void ViewLayer::MainLoop()
	{
		mDrawManager->InitDraw();
		while (true)
		{
			if (mInputManager->Check())
			{
				
			}
		}
	}
}