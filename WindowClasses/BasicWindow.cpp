#include "BasicWindow.h"

namespace myconsolewindows
{
	BasicWindow::BasicWindow()
	{
	}
	BasicWindow::BasicWindow(wstring name, int x, int y, int w, int h, HANDLE &console,WindowCommand *command, IDrawAlgorithm *drAl, ICleanAlgorithm *clAl) :
		mName(name), hConsole(console),mInnerCommand(command), mDrawAlgorithm(drAl), mCleanAlgorithm(clAl)
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

	void BasicWindow::Draw()
	{
		if (mDrawAlgorithm)
			mDrawAlgorithm->Draw(this);
	}
	void BasicWindow::Clean()
	{
		if (mCleanAlgorithm)
			mCleanAlgorithm->Clean(this);
	}

	WindowCommand* BasicWindow::GetInnerCommand()
	{
		return mInnerCommand;
	}
	void BasicWindow::SetInnerCommand(WindowCommand* command)
	{
		if (!mInnerCommand)
			mInnerCommand = command;
	}

	void BasicWindow::SetExtraCommand(WindowCommand* command)
	{
		if (mExtraCommand)
			delete mExtraCommand;
		mExtraCommand = command;
	}
	WindowCommand* BasicWindow::GetExtraCommand()
	{
		return mExtraCommand;
	}
}


