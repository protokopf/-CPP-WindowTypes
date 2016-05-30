#include "WindowCreationFunctions.h"
#include "BasicWindow.h"
#include "PluralWindow.h"

using namespace std;

namespace myconsolewindows
{
	BasicWindow* CreatePluralWindow(BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE& console,
		COLORS marked = COLORS::Marked, COLORS back = COLORS::Back, COLORS font = COLORS::Font)
	{
		return new PluralWindow(actWindow, name, x, y, w, h, console, marked, back, font);
	}
}