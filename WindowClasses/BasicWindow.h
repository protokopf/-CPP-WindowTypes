#ifndef BAS_WIN_H
#define BAS_WIN_H

#include <Windows.h>
#include "Enums.h"
#include <list>
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

		COORD mPosition;
		COORD mSize;

		bool mIsChanged;
		bool mIsInteractable;
		bool mIsHidden;
		bool mIsDeleted;

		list<BasicWindow*> mChilds;
		BasicWindow* mParent;
		wstring mName;

		void DeleteChilds();
	public:
		BasicWindow();
		BasicWindow(wstring name, int x, int y, int w, int h, HANDLE &console);

		int GetCurrentChildIndex();
		void SetCurrentChildIndex(int index);

		BasicWindow* GetParent();
		void SetParent(BasicWindow* parent);

		wstring GetName();
		void   SetName(const wstring &name);

		bool IsChanged() { return mIsChanged; }
		bool SetChanged(bool value) { mIsChanged = value; }

		bool IsInteractable() { return mIsInteractable; }
		bool SetInteractable(bool value) { mIsInteractable = value; }

		bool IsHidden() { return mIsHidden; }
		bool SetHidden(bool value) { mIsHidden = value; }

		bool IsDeleted() { return mIsDeleted; }
		bool SetDeleted(bool value) { mIsDeleted = value; }

		COORD GetPosition() { return mPosition; }
		COORD GetSize() { return mSize; }

		HANDLE GetConsoleHandle() { return hConsole; }

		void HideWindow(bool reallyShow);
		void SetColor  (int font, int back)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((back << 4) | font));
		}

		virtual void AddChildWindow(BasicWindow* child);
		virtual ~BasicWindow();
	};
}
#endif

