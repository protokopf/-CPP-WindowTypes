#ifndef WINDOWS_MANAGER
#define WINDOWS_MANAGER

#include <string>
#include <map>
using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;

	class WindowsManagerInterface
	{
	public:
		virtual void AddWindow(BasicWindow *window) = 0;
		virtual BasicWindow* operator[](wstring windowPath) = 0;
		virtual ~WindowsManagerInterface(){}
	};

	class WindowsManager : public WindowsManagerInterface
	{
	private:
		map<wstring, BasicWindow*> mWindows;
		void RecursiveAdding(BasicWindow *window, wstring &path);
	public:
		WindowsManager(BasicWindow* window);
		void AddWindow(BasicWindow *window);
		BasicWindow* operator[](wstring windowPath);
	};
}


#endif