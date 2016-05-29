#ifndef WIN_CREAT_Manager
#define WIN_CREAT_Manager

#include <string>
#include <map>

using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;

	class WindowCreatorManager
	{
	public:
		using CreateWindowCallBack = BasicWindow*(string name, int x, int y, int w, int h);
	private:
		using CallBackMap = map < string, CreateWindowCallBack* > ;
	public:
		WindowCreatorManager(const WindowCreatorManager&) = delete;
		WindowCreatorManager() = default;

		bool RegisternWindow(string winId, CreateWindowCallBack* winFunc);
		bool UnregisterWindow(string windId);

		BasicWindow* CreateMyWindow(string winId, string name, int x, int y, int h, int w);
	private:
		
		CallBackMap mCallBacks;
	};
}

#endif