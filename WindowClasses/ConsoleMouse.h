#ifndef CONSOLE_MOUSE
#define CONSOLE_MOUSE

#include <Windows.h>

namespace myconsolewindows
{
	class ConsoleMouse
	{
	private:
		HWND  hwConsole;
		RECT  rectConsole;
		COORD fontSize;

		POINT pCursorAbs;
		POINT pCursorRel;
		POINT pCursorSym;

		bool wasClicked;

		void PrepareInformation();
		void CutWindowRect();
	public:
		ConsoleMouse();

		bool WasClicked();
		void WasClicked(bool clicked);
		bool IsCursorInConsole();
		POINT GetCursorPositionInSymbols();
		POINT GetCursorPositionInPixels();

	};
}

#endif