#include "DrawManager.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
	#pragma region DrawManagerInterface

#pragma endregion

	#pragma region WindowDrawManager

	void WindowDrawManager::InitDraw()
	{
		for (auto win : (*refToAllWindows))
			if (!win->IsHidden())
				win->Draw();
	}
	void WindowDrawManager::DrawWindows()
	{
		for (auto win : (*refToAllWindows))
		{
			if (!win->IsHidden() && win->IsChanged())
			{
				win->Clean();
				if (!win->IsDeleted())
				{
					win->Draw();
					win->IsChanged(false);
				}
			}
		}
	}

#pragma endregion
}