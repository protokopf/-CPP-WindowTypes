#include "ViewLayer.h"
#include "IWinCommand.h"
#include <conio.h>

#include "ConsoleMouse.h"
#include <iostream>

using namespace std;
using namespace myconsolewindows;


int main()
{
	//ViewLayer layer;
	//layer.MainLoop();

	ConsoleMouse mouse;
	while (true)
	{
		if (mouse.IsCursorInConsole())
		{
			cout << mouse.GetCursorPositionInSymbols().x << " : " << mouse.GetCursorPositionInSymbols().y << endl;
		}
	}

	system("pause");

	return 0;
}
