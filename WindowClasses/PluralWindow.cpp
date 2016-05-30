#include "PluralWindow.h"
#include "IDrawableAlgorithms.h"

namespace myconsolewindows
{
	#pragma region Конструкторы и деструктор
	PluralWindow::PluralWindow() : BasicWindow()
	{

	}
	PluralWindow::PluralWindow(BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE &console, COLORS marked, COLORS back, COLORS font) :
		BasicWindow(name, x, y, w, h, console, new BorderDrawAlgorithm(), new BorderCleanAlgorithm(),
		new GoToChildWindowCommand(actWindow),marked,back,font)
	{

	}

	PluralWindow::~PluralWindow()
	{
	}
#pragma endregion

	#pragma region Сэттэры и геттэры


#pragma endregion

	#pragma region Методы класса

#pragma endregion
}
