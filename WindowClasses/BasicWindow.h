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
	private:
		int mCurrentChildIndex = 0;
		HANDLE hConsole;

		COLORS backColor;
		COLORS fontColor;

		COORD mPosition;
		COORD mSize;

		bool mIsChanged;
		bool mIsClicked;

		bool mIsInteractable;
		bool mIsHidden;
		bool mIsDeleted;

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
		BasicWindow(wstring name, int x, int y, int w, int h, HANDLE &console,WindowCommand* command = nullptr, IDrawAlgorithm *drAl = nullptr, ICleanAlgorithm *clAl = nullptr);

		void HideWindow(bool reallyShow);
		void InFocus();
		void OutFocus();

		virtual void AddChildWindow(BasicWindow* child);
		virtual void Draw();
		virtual void Clean();

		int GetCurrentChildIndex();
		void SetCurrentChildIndex(int index);

		BasicWindow* GetParent();
		void SetParent(BasicWindow* parent);

		wstring GetName();
		void   SetName(const wstring &name);

		bool IsClicked() { return mIsClicked; }
		void IsClicked(bool clicked) { mIsClicked = clicked; }

		bool IsChanged() { return mIsChanged; }
		void IsChanged(bool value) { mIsChanged = value; }

		bool IsInteractable() { return mIsInteractable; }
		void IsInteractable(bool value) { mIsInteractable = value; }

		bool IsHidden() { return mIsHidden; }
		void IsHidden(bool value) { mIsHidden = value; }

		bool IsDeleted() { return mIsDeleted; }
		void IsDeleted(bool value) { mIsDeleted = value; mIsChanged = value; }

		COORD GetPosition() { return mPosition; }
		COORD GetSize() { return mSize; }

		HANDLE GetConsoleHandle() { return hConsole; }
		void SetColor  (COLORS font, COLORS back)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((back << 4) | font));
			fontColor = font;
			backColor = back;
		}

		COLORS GetBack() { return backColor; }
		COLORS GetFont() { return fontColor; }

		vector<BasicWindow*>* GetChilds() { return mChilds; }

		WindowCommand* GetInnerCommand();
		void SetInnerCommand(WindowCommand* command);

		vector<WindowCommand*>& GetExtraCommands();
		void SetExtraCommand(WindowCommand* command);

		virtual ~BasicWindow();
	};
}
#endif

