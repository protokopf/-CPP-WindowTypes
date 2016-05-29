#include "DrawManager.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
	#pragma region DrawManagerInterface
	void DrawManagerInterface::RecursiveAdding(BasicWindow *root)
	{
		mWindows.push_back(root);
		for (auto child : root->GetChilds())
			RecursiveAdding(child);
	}
#pragma endregion

	#pragma region WindowDrawManager

	void WindowDrawManager::InitDraw()
	{
		for (auto win : mWindows)
			if (!win->IsHidden())
				win->Draw();
	}
	void WindowDrawManager::DrawWindows()
	{
		for (auto win : mWindows)
		{
			if (!win->IsHidden() && win->IsChanged())
			{
				win->Clean();
				if (!win->IsDeleted())
					win->Draw();
			}
		}
	}

#pragma endregion
}