#ifndef BAS_WIN_H
#define BAS_WIN_H

#include "IDrawableAlgorithms.h"
#include "IWinCommand.h"
#include "Enums.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

namespace myconsolewindows
{
	// Перед созданием какого-то окна в каркасе нужно настроить консольку (убрать курсор, установить размер)
	class BasicWindow
	{
	protected:
		int mCurrentChildIndex = 0;
		HANDLE hConsole;

		COLORS backColor;
		COLORS fontColor;

		COLORS markedColor;
		COLORS unmarkedColor;

		COORD mPosition;
		COORD mSize;

		bool mIsChanged = false;
		bool mIsClicked = false;

		bool mIsInteractable = true;
		bool mIsHidden = false;
		bool mIsDeleted = false;

		vector<BasicWindow*>* mChilds = nullptr;
		BasicWindow* mParent = nullptr;

		wstring mName;

		IDrawAlgorithm *mDrawAlgorithm;
		ICleanAlgorithm *mCleanAlgorithm;

		WindowCommand* mInnerCommand = nullptr;
		vector<WindowCommand*> mExtraCommands;

		void DeleteChilds();
	public:
		BasicWindow();
		BasicWindow(wstring name, int x, int y, int w, int h, HANDLE &console, IDrawAlgorithm *drAl, ICleanAlgorithm *clAl, WindowCommand* command,
			COLORS marked, COLORS back, COLORS font);

		void HideWindow(bool reallyShow);
		void InFocus();
		void OutFocus();

		virtual void AddChildWindow(BasicWindow* child);
		virtual void Draw() const;
		virtual void Clean() const;

		int GetCurrentChildIndex() const;
		void SetCurrentChildIndex(int index);

		BasicWindow* GetParent();
		void SetParent(BasicWindow* parent);

		wstring GetName() const;
		void   SetName(const wstring &name);

		bool IsClicked() const { return mIsClicked; }
		void IsClicked(bool clicked) { mIsClicked = clicked; }

		bool IsChanged() const { return mIsChanged; }
		void IsChanged(bool value) { mIsChanged = value; }

		bool IsInteractable() const { return mIsInteractable; }
		void IsInteractable(bool value) { mIsInteractable = value; }

		bool IsHidden() const { return mIsHidden; }
		void IsHidden(bool value) { mIsHidden = value; }

		bool IsDeleted() const { return mIsDeleted; }
		void IsDeleted(bool value) { mIsDeleted = value; mIsChanged = value; }

		COORD GetPosition() const { return mPosition; }
		COORD GetSize() const { return mSize; }

		HANDLE GetConsoleHandle() const { return hConsole; }
		void SetColor  (COLORS font, COLORS back)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((back << 4) | font));
			fontColor = font;
			backColor = back;
		}

		COLORS GetBack() const { return backColor; }
		COLORS GetFont() const { return fontColor; }

		vector<BasicWindow*>* GetChilds() { return mChilds; }

		WindowCommand* GetInnerCommand();
		void SetInnerCommand(WindowCommand* command);

		vector<WindowCommand*>& GetExtraCommands();
		void SetExtraCommand(WindowCommand* command);

		virtual ~BasicWindow();
	};
}
#endif

