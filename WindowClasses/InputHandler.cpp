#include "InputHandler.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
#pragma region InputHandlerInterface
	InputHandlerInterface::InputHandlerInterface(BasicWindow*& refToCurWinPtr) : 
		refToCurrentWindowPtr(refToCurWinPtr)
	{

	}
#pragma endregion


}