#include <string>
#include "Enums.h"
#include <Windows.h>
using namespace std;
namespace myconsolewindows
{
	extern class BasicWindow;

	BasicWindow* CreatePluralWindow(BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE& console,
		COLORS marked, COLORS back, COLORS font);

}