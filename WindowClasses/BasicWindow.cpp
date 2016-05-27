#include "BasicWindow.h"

namespace myconsolewindows
{
	BasicWindow::BasicWindow()
	{
	}
	BasicWindow::BasicWindow(wstring name, int x, int y, int w, int h, HANDLE &console) : 
		mName(name), hConsole(console)
	{
		mSize = { w, h };
		mPosition = { x, y };
	}

	BasicWindow::~BasicWindow()
	{
	}

	void	BasicWindow::DeleteChilds()
	{
		for (auto it = mChilds.begin(); it != mChilds.end(); ++it)
			delete (*it);
	}

	int		BasicWindow::GetCurrentChildIndex()
	{
		return mCurrentChildIndex;
	}
	void	BasicWindow::SetCurrentChildIndex(int index)
	{
		mCurrentChildIndex = index;
	}

	BasicWindow* BasicWindow::GetParent()
	{
		return mParent;
	}
	void BasicWindow::SetParent(BasicWindow* parent)
	{
		mParent = parent;
	}

	wstring BasicWindow::GetName()
	{
		return mName;
	}
	void   BasicWindow::SetName(const wstring &name)
	{
		mName = name;
	}

	void BasicWindow::HideWindow(bool isHidden)
	{
		this->mIsHidden = isHidden;
		for (auto it : mChilds)
			it->HideWindow(isHidden);
	}
	void BasicWindow::AddChildWindow(BasicWindow* child)
	{
		mChilds.push_back(child);
		child->mParent = this;
	}
}


