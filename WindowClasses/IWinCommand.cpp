#include "IWinCommand.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
#pragma region InnerWindowCommand

	InnerWindowCommand::InnerWindowCommand(BasicWindow *goalWindow)
	{
		commandedWindow = goalWindow;
	}

	void InnerWindowCommand::Execute()
	{
		if (commandedWindow)
			commandedWindow->GetInnerCommand()->Execute();
	}
#pragma endregion
}