#ifndef VIEW_LAYER_H
#define VIEW_LAYER_H
#include "BasicWindow.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "WindowCreatorManager.h"
#include "WindowCreationFunctions.h"

#include <conio.h>
#include <iostream>


namespace myconsolewindows
{
	class ViewLayer
	{
	private:
		HANDLE       mConsoleHandle;

		BasicWindow* mActiveWindow;

		InputManagerInterface* mInputManager = nullptr;
		DrawManagerInterface* mDrawManager = nullptr;
		WindowCreatorManager* mCreatorManager = nullptr;

		void SetUpConsole();
		void SetUpCreator();
	public:
		ViewLayer();


		void MainLoop();
	};
}
#endif