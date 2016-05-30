#ifndef PLURAL_WINDOW
#define PLURAL_WINDOW

#include "BasicWindow.h"
#include <string>
using namespace std;

namespace myconsolewindows
{
	class PluralWindow : public BasicWindow
	{
	public:
		PluralWindow();
		PluralWindow(BasicWindow*& actWindow, wstring name, int x, int y, int w, int h, HANDLE &console, COLORS marked, COLORS back, COLORS font);

		virtual ~PluralWindow();
	};
}
#endif 

