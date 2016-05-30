#ifndef WIN_CREAT_Manager
#define WIN_CREAT_Manager

#include <string>
#include <map>
#include <conio.h>
#include <Windows.h>
#include "Enums.h"

using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;

	class WindowCreatorManager
	{
	public:
		using CreateWindowCallBack = BasicWindow*(BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE &console, 
			COLORS marked, COLORS back, COLORS font);
	private:
		using CallBackMap = map<wstring, CreateWindowCallBack*>;
	public:
		WindowCreatorManager(const WindowCreatorManager&) = delete;
		WindowCreatorManager() = default;

		bool RegisternWindow(wstring winId, CreateWindowCallBack* winFunc);
		bool UnregisterWindow(wstring windId);

		BasicWindow* CreateMyWindow(wstring winId, BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE &console, COLORS marked = COLORS::Marked, COLORS back = COLORS::Back, COLORS font = COLORS::Font);
	private:
		
		CallBackMap mCallBacks;
	};
}

#endif