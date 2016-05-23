#ifndef VIEW_LAYER_H
#define VIEW_LAYER_H

#include "BasicWindow.h"


namespace myconsolewindows
{
	class ViewLayer
	{
	private:
		BasicWindow* mActiveWindow;
		HANDLE       mConsoleHandle;

		void SetUpConsole();
	public:
		ViewLayer();

		void MainLoop();
	};
}
#endif