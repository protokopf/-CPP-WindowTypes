#include "ConsoleMouse.h"

namespace myconsolewindows
{
	using cm = ConsoleMouse;

#pragma region Конструкторы и деструктора
	cm::ConsoleMouse()
	{
		hwConsole = GetConsoleWindow();
		PrepareInformation();
	}
#pragma endregion

#pragma region Сэттэры и геттэры
	void cm::WasClicked(bool clicked)
	{
		wasClicked = clicked;
	}
	bool cm::WasClicked()
	{
		return wasClicked;
	}
#pragma endregion

#pragma region Методы класса
	bool cm::IsCursorInConsole()
	{
		PrepareInformation();
		return (pCursorAbs.x >= rectConsole.left && pCursorAbs.x <= rectConsole.right)
			&& (pCursorAbs.y >= rectConsole.top && pCursorAbs.y <= rectConsole.bottom);
	}

	void cm::PrepareInformation()
	{
		GetWindowRect(hwConsole, &rectConsole);
		GetCursorPos(&pCursorAbs);
		CutWindowRect();
		pCursorRel.x = pCursorAbs.x - rectConsole.left;
		pCursorRel.y = pCursorAbs.y - rectConsole.top;
	}
	void cm::CutWindowRect()
	{
		rectConsole.left += 10;
		rectConsole.right -= 10;
		rectConsole.bottom -= 10;
		rectConsole.top += 32;
	}

	POINT cm::GetCursorPositionInPixels()
	{
		return pCursorRel;
	}
	POINT cm::GetCursorPositionInSymbols()
	{
		// реализовать метод
		return pCursorRel;
	}

#pragma endregion
}