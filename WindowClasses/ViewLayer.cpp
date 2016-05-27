#include "ViewLayer.h"


namespace myconsolewindows
{
	void ViewLayer::SetUpConsole()
	{
		mConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cci;
		cci.dwSize = 100;
		cci.bVisible = false;
		SetConsoleCursorInfo(mConsoleHandle, &cci);

		
		
	}
	void ViewLayer::InitialDraw()
	{

	}

	void ViewLayer::MainLoop()
	{
		InitialDraw();
		while (true)
		{
			if (_kbhit())
			{
				char key = 0;
				cin >> key;
			}
		}
	}
}