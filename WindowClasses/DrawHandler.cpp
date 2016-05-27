#include "DrawHandler.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
#pragma region DrawHandlerInterface
	void DrawHandlerInterface::RecursiveAdding(BasicWindow *root)
	{
		mWindows.push_back(root);
		for (auto child : root->GetChilds())
			RecursiveAdding(child);
	}
#pragma endregion
}