#include "CommandManager.h"
#include "BasicWindow.h"
#include "IWinCommand.h"
#include <algorithm>

namespace myconsolewindows
{
#pragma region Конструкторы и деструкторы
	CommandManager::CommandManager(vector<BasicWindow*>* refToVector) : CommandManagerInterface(refToVector)
	{
	}
#pragma endregion

#pragma region Сэттеры и геттеры

#pragma endregion

#pragma region Методы класса
	void CommandManager::ExecuteCommands()
	{
		for (auto window : (*refToAllWindows))
		{
			if (window->IsInteractable())
			{
				auto commands = window->GetExtraCommands();
				if (commands.size() > 0)
				{
					for (int j = 0; j < commands.size(); ++j)
					{
						commands[j]->Execute();
						delete commands[j];
					}
					window->GetExtraCommands().clear();
				}
			}
		}
	}
#pragma endregion
}