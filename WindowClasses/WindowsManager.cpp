#include "WindowsManager.h"
#include "BasicWindow.h"

namespace myconsolewindows
{
#pragma region Конструкторы и деструкторы
	WindowsManager::WindowsManager(BasicWindow* window, vector<BasicWindow*>& refToVector) : refToAllWindows(refToVector)
	{
		AddWindow(window);
	}
#pragma endregion

#pragma region Сэттеры и геттеры

#pragma endregion

#pragma region Методы класса
	BasicWindow* WindowsManager::operator[](wstring path)
	{
		auto it = mWindows.find(path);
		if (it == mWindows.end())
			return nullptr;
		return (*it).second;
	}

	void WindowsManager::RecursiveAdding(BasicWindow* window, wstring& path)
	{
		int startIndex = path.size();
		path.append(wstring(L".") + window->GetName());

		mWindows.insert({ path, window });
		refToAllWindows.push_back(window);

		for (auto child : (*window->GetChilds()))
			RecursiveAdding(child, path);
		path.erase(path.begin() + startIndex, path.begin() + window->GetName().size() + 1);
	}
	void WindowsManager::AddWindow(BasicWindow *window)
	{
		wstring path = window->GetName();
		mWindows.insert({ path, window });
		refToAllWindows.push_back(window);
		for (auto child : (*window->GetChilds()))
			RecursiveAdding(child, path);
	}
#pragma endregion
}