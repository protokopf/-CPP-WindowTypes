#ifndef VIEW_LAYER_H
#define VIEW_LAYER_H
#include "BasicWindow.h"
#include <conio.h>
#include <iostream>


namespace myconsolewindows
{
	class ViewLayer
	{
	private:
		BasicWindow* mActiveWindow;
		HANDLE       mConsoleHandle;

		void SetUpConsole();
		void InitialDraw();
	public:
		ViewLayer();

		void MainLoop();
	};
}
#endif