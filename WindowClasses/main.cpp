#include "ViewLayer.h"

using namespace std;
using namespace myconsolewindows;


int main()
{
	//ViewLayer v;
	//v.MainLoop();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	LPDWORD length = new DWORD;
	COORD winPos = {10,10};
	COORD winSize = { 10, 10 };
	int maxY = winPos.Y + winSize.Y;
	int maxX = winPos.X + winSize.X;
	auto handle = h;

	WORD color = (WORD)((COLORS::White << 4) | COLORS::Black);

	FillConsoleOutputAttribute(handle, color, winSize.X - 1, { winPos.X + 1, winPos.Y }, length);
	FillConsoleOutputAttribute(handle, color, winSize.X - 1, { winPos.X + 1, winPos.Y }, length);

	FillConsoleOutputCharacterW(handle, BORDER::UpBorder, winSize.X - 1, { winPos.X + 1, winPos.Y }, length);
	FillConsoleOutputCharacterW(handle, BORDER::DownBorder, winSize.X - 1, { winPos.X + 1, maxY }, length);

	FillConsoleOutputAttribute(handle, color, 1, winPos, length);
	FillConsoleOutputCharacterW(handle, BORDER::LeftUpCorner, 1, winPos, length);
	FillConsoleOutputAttribute(handle, color, 1, { maxX, winPos.Y }, length);
	FillConsoleOutputCharacterW(handle, BORDER::RightUpCorner, 1, { maxX, winPos.Y }, length);
	FillConsoleOutputAttribute(handle, color, 1, { winPos.X, maxY }, length);
	FillConsoleOutputCharacterW(handle, BORDER::LeftDownCorner, 1, { winPos.X, maxY }, length);
	FillConsoleOutputAttribute(handle, color, 1, { maxX, maxY }, length);
	FillConsoleOutputCharacterW(handle, BORDER::RightDownCorner, 1, { maxX, maxY }, length);

	for (int y = winPos.Y + 1; y < maxY; ++y)
	{
		FillConsoleOutputAttribute(handle, color, 1, { winPos.X, y }, length);
		FillConsoleOutputCharacterW(handle, BORDER::LeftBorder, 1, { winPos.X, y }, length);
		FillConsoleOutputAttribute(handle, color, 1, { maxX, y }, length);
		FillConsoleOutputCharacterW(handle, BORDER::RightBorder, 1, { maxX, y }, length);
	}


	color = (WORD)((COLORS::Green << 4) | COLORS::Black);

	for (int y = winPos.Y + 1; y < maxY; ++y)
	{
		FillConsoleOutputAttribute(handle, color, winSize.X - 1, { winPos.X + 1, y }, length);
		FillConsoleOutputCharacterW(handle, L' ', winSize.X - 1, { winPos.X + 1, y }, length);
	}


	while (true){}
	system("pause");

	return 0;
}