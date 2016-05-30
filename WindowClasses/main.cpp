#include "ViewLayer.h"
#include "IWinCommand.h"
#include <conio.h>

using namespace std;
using namespace myconsolewindows;


int main()
{
	ViewLayer layer;
	layer.MainLoop();

	system("pause");

	return 0;
}
