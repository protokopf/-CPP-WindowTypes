#include "IWinCommand.h"
#include "BasicWindow.h"
#include <algorithm>

namespace myconsolewindows
{
	#pragma region InnerWindowCommand
	void InnerWindowCommand::Execute()
	{
		if (commandedWindow)
			commandedWindow->GetInnerCommand()->Execute();
	}
#pragma endregion

	#pragma region GoToParentWindowCommand
	void GoToParentWindowCommand::Execute()
	{
		if (commandedWindow->GetParent() != nullptr)
		{
			auto childs = commandedWindow->GetChilds();
			for_each((*childs).begin(), (*childs).end(), [](BasicWindow *win) {win->OutFocus(); });
			commandedWindow = commandedWindow->GetParent();
			(*commandedWindow->GetChilds())[commandedWindow->GetCurrentChildIndex()]->InFocus();
		}
	}
#pragma endregion

	#pragma region GoToNextChildWindowCommand
	void GoToNextChildWindowCommand::Execute()
	{
		auto childs = commandedWindow->GetChilds();
		auto currentIndex = commandedWindow->GetCurrentChildIndex();
		for (int i = currentIndex; i < (*childs).size(); ++i)
		{
			if (!(*childs)[i]->IsHidden())
			{
				(*childs)[currentIndex]->OutFocus();
				(*childs)[i]->InFocus();
				currentIndex = i;
				break;
			}
		}
	}
#pragma endregion

	#pragma region GoToPrevChildWindowCommand
	void GoToPrevChildWindowCommand::Execute()
	{
		auto childs = commandedWindow->GetChilds();
		auto currentIndex = commandedWindow->GetCurrentChildIndex();
		for (int i = currentIndex; i >= 0; --i)
		{
			if (!(*childs)[i]->IsHidden())
			{
				(*childs)[currentIndex]->OutFocus();
				(*childs)[i]->InFocus();
				currentIndex = i;
				break;
			}
		}
	}
#pragma endregion
}