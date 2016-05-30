#include "BasicWindow.h"

namespace myconsolewindows
{
#pragma region Конструкторы и деструкторы
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
		DeleteChilds();
		delete mChilds;

		delete mDrawAlgorithm;
		delete mCleanAlgorithm;

		delete mInnerCommand;
		for (auto command : mExtraCommands)
			delete command;
		mExtraCommands.clear();
	}
#pragma endregion

#pragma region Геттеры и Сеттеры

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
		mExtraCommands.push_back(command);
	}
	vector<WindowCommand*>& BasicWindow::GetExtraCommands()
	{
		return mExtraCommands;
	}

#pragma endregion

#pragma region Методы Класса
	void BasicWindow::HideWindow(bool isHidden)
	{
		this->mIsHidden = isHidden;
		for (auto it : (*mChilds))
			it->HideWindow(isHidden);
	}

	void BasicWindow::AddChildWindow(BasicWindow* child)
	{
		if (mChilds == nullptr)
			mChilds = new vector<BasicWindow*>();
		mChilds->push_back(child);
		child->mParent = this;
	}
	void	BasicWindow::DeleteChilds()
	{
		for (auto it = mChilds->begin(); it != mChilds->end(); ++it)
			delete (*it);
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

	void BasicWindow::InFocus()
	{
		backColor = COLORS::Red;
		IsChanged(true);
	}
	void BasicWindow::OutFocus()
	{
		backColor = COLORS::White;
		IsChanged(true);
	}
#pragma endregion
}


