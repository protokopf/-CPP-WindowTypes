#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>

using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;
	class CommandManagerInterface
	{
	protected:
		vector<BasicWindow*>& refToAllWindows;
	public:
		CommandManagerInterface(vector<BasicWindow*>& refToVector) : refToAllWindows(refToVector) {}

		virtual void ExecuteCommands() = 0;
		virtual ~CommandManagerInterface() {}
	};

	class CommandManager : public CommandManagerInterface
	{
	public:
		CommandManager(vector<BasicWindow*>& refToVector);

		void ExecuteCommands() override;
	};
}



#endif