#include "InputManager.h"
#include "BasicWindow.h"
#include "Enums.h"
#include <conio.h>
#include <iostream>

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
		if (_kbhit() && KeyReact(_getch()))
			return true;
		return false;
	}

	bool BasicKeyboardInputManager::KeyReact(wchar_t key)
	{
		switch (key)
		{
		case MOVES::UP:
		case MOVES::RIGHT:
			refToCurrentWindowPtr->SetExtraCommand(new SlideToNextChildWindowCommand(refToCurrentWindowPtr));
			return true;
		case MOVES::DOWN:
		case MOVES::LEFT:
			refToCurrentWindowPtr->SetExtraCommand(new SlideToPrevChildWindowCommand(refToCurrentWindowPtr));
			return true;
		case MOVES::ENTER:
			refToCurrentWindowPtr->IsClicked(true);
			refToCurrentWindowPtr->SetExtraCommand(new InnerWindowCommand(refToCurrentWindowPtr));
			return true;
		case MOVES::ESC:
			refToCurrentWindowPtr->SetExtraCommand(new GoToParentWindowCommand(refToCurrentWindowPtr));
			return true;
		default:
			return false;
		}

	}

#pragma endregion

#pragma region MouseKeyboardInputManager
	using mkim = MouseKeyboardInputManager;
	void mkim::CutWindowRect()
	{
		rectConsole.left += 10;
		rectConsole.right -= 10;
		rectConsole.bottom -= 10;
		rectConsole.top += 32;
	}
	bool mkim::IntersectConsoleRect()
	{
		return (posCursor.x >= rectConsole.left && posCursor.x <= rectConsole.right)
			&& (posCursor.y >= rectConsole.top && posCursor.y <= rectConsole.bottom);
	}

	bool mkim::CheckMouseInput()
	{
		GetWindowRect(hwndConsole, &rectConsole);
		GetCursorPos(&posCursor);
		CutWindowRect();
		if (IntersectConsoleRect())
		{

		}
		return true;
	}
	
	bool mkim::Check()
	{
		if (CheckMouseInput())
			return true;

		if (_kbhit() && (KeyReact(_getch())));
			return true;
		return false;
	}

#pragma endregion


}