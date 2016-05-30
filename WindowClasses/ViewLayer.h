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
#include <vector>


namespace myconsolewindows
{
	class ViewLayer
	{
	private:
		HANDLE       mConsoleHandle;

		BasicWindow* mActiveWindow;
		vector<BasicWindow*> allWindows;

		InputManagerInterface* mInputManager = nullptr;
		DrawManagerInterface* mDrawManager = nullptr;
		CommandManagerInterface* mCommandManager = nullptr;
		WindowCreatorManager* mCreatorManager = nullptr;
		WindowsManagerInterface* mWindowsManager = nullptr;

		void SetUpConsole();
		void SetUpCreator();

		void HelloWorld() { cout << "HelloWorld!\n"; }
	public:
		ViewLayer();

		void MainLoop();
		void TestMethod()
		{
			WindowCommand *command = new LayerMethodWindowCommand(mActiveWindow, this, &ViewLayer::HelloWorld);
			command->Execute();
		}

		~ViewLayer();
	};
}
#endif