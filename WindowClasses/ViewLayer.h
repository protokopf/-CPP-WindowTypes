#ifndef VIEW_LAYER_H
#define VIEW_LAYER_H
#include "BasicWindow.h"
#include "InputHandler.h"
#include "DrawHandler.h"
#include <conio.h>
#include <iostream>


namespace myconsolewindows
{
	class ViewLayer
	{
	private:
		HANDLE       mConsoleHandle;

		BasicWindow* mActiveWindow;

		InputHandlerInterface* mInputHandler;
		DrawHandlerInterface* mDrawHandler;

		void SetUpConsole();
	public:
		ViewLayer() = default;

		void MainLoop();
	};
}
#endif