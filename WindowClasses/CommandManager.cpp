#include "CommandManager.h"
#include "BasicWindow.h"
#include "IWinCommand.h"
#include <algorithm>

namespace myconsolewindows
{
#pragma region ������������ � �����������
	CommandManager::CommandManager(vector<BasicWindow*>* refToVector) : CommandManagerInterface(refToVector)
	{
	}
#pragma endregion

#pragma region ������� � �������

#pragma endregion

#pragma region ������ ������

	void CommandManager::ExecuteCommands()
	{
		for (int i = 0; i < refToAllWindows->size(); ++i)
		{
			auto commands = (*refToAllWindows)[i]->GetExtraCommands();
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