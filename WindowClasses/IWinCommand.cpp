#include "IWinCommand.h"
#include "BasicWindow.h"
#include "ViewLayer.h"
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
		if (commandedWindow->GetParent())
		{
			auto childs = commandedWindow->GetChilds();
			for_each((*childs).begin(), (*childs).end(), [](BasicWindow *win) {win->OutFocus(); });
			commandedWindow = commandedWindow->GetParent();
			(*commandedWindow->GetChilds())[commandedWindow->GetCurrentChildIndex()]->InFocus();
		}
	}
#pragma endregion
	#pragma region GoToChildWindowCommand
	void GoToChildWindowCommand::Execute()
	{
		auto childIndex = commandedWindow->GetCurrentChildIndex();
		auto childs = commandedWindow->GetChilds();
		commandedWindow->OutFocus();
		commandedWindow = (*childs)[childIndex];
		commandedWindow->InFocus();
	}
#pragma endregion

	#pragma region SlideToNextChildWindowCommand
	void SlideToNextChildWindowCommand::Execute()
	{
		auto childs = commandedWindow->GetChilds();
		if (childs)
		{
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
	}
#pragma endregion
	#pragma region SlideToPrevChildWindowCommand
	void SlideToPrevChildWindowCommand::Execute()
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

	#pragma region LayerMethodWindowCommand
	using lmwc = LayerMethodWindowCommand;

	lmwc::LayerMethodWindowCommand(BasicWindow*& window, ViewLayer* lpLayer, lmwc::ViewLayerMethod lpMethod):
		WindowCommand(window)
	{
		ptrToLayer = lpLayer;
		ptrToMethod = lpMethod;
	}

	void lmwc::Execute()
	{
		if (ptrToLayer && ptrToMethod)
			(ptrToLayer->*ptrToMethod)();
	}

#pragma endregion
}