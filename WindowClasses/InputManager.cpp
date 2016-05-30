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

	bool mkim::Check()
	{
		if (mMouse.IsCursorInConsole())
			if (CheckIntersectionWithWindows(mMouse.GetCursorPositionInSymbols()))
				return true;
		if (_kbhit() && (KeyReact(_getch())));
			return true;
		return false;
	}

	bool mkim::IsWindowContainPoint(BasicWindow* window, POINT point)
	{
		auto winPos = window->GetPosition();
		auto winSize = window->GetSize();
		return (point.x >= (winPos.X) && point.x <= (winPos.X + winSize.X)) &&
			(point.y >= (winPos.Y) && point.y <= (winPos.Y + winSize.Y));
	}
	bool mkim::CheckIntersectionWithWindows(POINT point)
	{
		auto childs = refToCurrentWindowPtr->GetChilds();
		if (childs)
		{
			for (int i = 0; i < childs->size(); ++i)
			{
				if (!(*childs)[i]->IsHidden() && (*childs)[i]->IsInteractable() && IsWindowContainPoint((*childs)[i], point))
				{
					refToCurrentWindowPtr->SetExtraCommand(new SlideToConcreteChildWindowCommand(refToCurrentWindowPtr, i));
					return true;
				}
			}
		}
		return false;
	}
#pragma endregion


}