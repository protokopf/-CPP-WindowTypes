#ifndef VIEW_LAYER_H
#define VIEW_LAYER_H

#include "BasicWindow.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "WindowCreatorManager.h"
#include "CommandManager.h"
#include "WindowsManager.h"

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
		CommandManagerInterface* mCommandManager = nullptr;
		WindowCreatorManager* mCreatorManager = nullptr;
		WindowsManagerInterface* mWindowsManager = nullptr;

		void SetUpConsole();
		void SetUpCreator();
	public:
		ViewLayer();

		void MainLoop();

		~ViewLayer();
	};
}
#endif