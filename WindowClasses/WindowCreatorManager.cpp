#include "WindowCreatorManager.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
	using wch = WindowCreatorManager;

	bool wch::RegisternWindow(string winId, wch::CreateWindowCallBack* function)
	{
		return mCallBacks.insert(CallBackMap::value_type(winId, function)).second;
	}
	bool wch::UnregisterWindow(string winId)
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

	BasicWindow* wch::CreateMyWindow(string winId, string name, int x, int y, int w, int h)
	{
		auto it = mCallBacks.find(winId);
		if (it == mCallBacks.end())
			throw std::runtime_error("Undefined window ID!");
		return (it->second)(name, x, y, w, h);
	}
}