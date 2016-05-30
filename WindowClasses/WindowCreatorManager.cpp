#include "WindowCreatorManager.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
	using wch = WindowCreatorManager;

	bool wch::RegisternWindow(wstring winId, wch::CreateWindowCallBack* function)
	{
		return mCallBacks.insert(CallBackMap::value_type(winId, function)).second;
	}
	bool wch::UnregisterWindow(wstring winId)
	{
		auto iterator = mCallBacks.find(winId);
		if (iterator == mCallBacks.end())
			return false;
		else
		{	
			mCallBacks.erase(iterator);
			return true;
		}
	}

	BasicWindow* wch::CreateMyWindow(wstring winId, BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE &console, COLORS marked, COLORS back, COLORS font)
	{
		auto it = mCallBacks.find(winId);
		if (it == mCallBacks.end())
			throw std::runtime_error("Undefined window ID!");
		return (it->second)(actWindow,name, x, y, w, h,console,marked,back,font);
	}
}