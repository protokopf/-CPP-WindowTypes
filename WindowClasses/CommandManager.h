#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>

using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;
	class CommandManagerInterface
	{
	public:
		virtual void AddWindow(BasicWindow* root) = 0;
		virtual void RemoveWindow(BasicWindow* root) = 0;

		virtual void ExecuteCommands() = 0;
		virtual ~CommandManagerInterface() {}
	};

	class CommandManager : public CommandManagerInterface
	{
	private:
		vector<BasicWindow*> mWindows;
	public:
		CommandManager(BasicWindow* window);

		void AddWindow(BasicWindow* root) override;
		void RemoveWindow(BasicWindow* root) override;

		void ExecuteCommands() override;
	};
}



#endif