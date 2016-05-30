#include "InputManager.h"
#include "BasicWindow.h"
#include "Enums.h"
#include <conio.h>

using namespace std;

namespace myconsolewindows
{
	#pragma region InputManagerInterface
	InputManagerInterface::InputManagerInterface(BasicWindow*& refToCurWinPtr) : 
		refToCurrentWindowPtr(refToCurWinPtr)
	{

	}
#pragma endregion

	#pragma region BasicKeyboardInputManager

	bool BasicKeyboardInputManager::Check()
	{
		if(_kbhit())
		{
			KeyReact(_getch());
			return true;
		}
		return false;
	}

	void BasicKeyboardInputManager::KeyReact(wchar_t key)
	{
		switch (key)
		{
		case MOVES::UP:
		case MOVES::RIGHT:
			refToCurrentWindowPtr->SetExtraCommand(new SlideToNextChildWindowCommand(refToCurrentWindowPtr));
			break;
		case MOVES::DOWN:
		case MOVES::LEFT:
			refToCurrentWindowPtr->SetExtraCommand(new SlideToPrevChildWindowCommand(refToCurrentWindowPtr));
			break;
		case MOVES::ENTER:
			refToCurrentWindowPtr->IsClicked(true);
			refToCurrentWindowPtr->SetExtraCommand(new InnerWindowCommand(refToCurrentWindowPtr));
			break;
		case MOVES::ESC:
			refToCurrentWindowPtr->SetExtraCommand(new GoToParentWindowCommand(refToCurrentWindowPtr));
			break;
		}
	}

#pragma endregion


}