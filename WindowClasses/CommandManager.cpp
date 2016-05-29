#include "CommandManager.h"
#include "BasicWindow.h"
#include "IWinCommand.h"
#include <algorithm>

namespace myconsolewindows
{
#pragma region Конструкторы и деструкторы
	CommandManager::CommandManager(BasicWindow* window)
	{
		AddWindow(window);
	}
#pragma endregion

#pragma region Сэттеры и геттеры

#pragma endregion

#pragma region Методы класса
	void CommandManager::AddWindow(BasicWindow* root)
	{
		mWindows.push_back(root);
		for (auto child : *(root->GetChilds()))
			AddWindow(child);
	}
	void CommandManager::RemoveWindow(BasicWindow* root)
	{
		for (auto child : *(root->GetChilds()))
			RemoveWindow(child);
		mWindows.erase(std::find(mWindows.begin(), mWindows.end(), root));
	}

	void CommandManager::ExecuteCommands()
	{
		for (int i = 0; i < mWindows.size(); ++i)
		{
			auto commands = mWindows[i]->GetExtraCommands();
			if (commands.size() > 0)
			{
				for (int j = 0; j < commands.size(); ++j)
				{
					commands[j]->Execute();
					delete commands[j];
				}
				commands.clear();
			}
		}
	}
#pragma endregion
}