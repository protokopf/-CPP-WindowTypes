#ifndef ENUMS_H
#define ENUMS_H

enum COLORS
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6,
	LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11,
	LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15,
	Marked = Red, Font = Black, Back = White
};
enum MOVES
{
	UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, ESC = 27, ENTER = 13, SPACE = 32
};
enum BORDER
{
	LeftUpCorner = 0x250c,
	RightUpCorner = 0x2510,
	LeftDownCorner = 0x2514,
	RightDownCorner = 0x2518,
	UpBorder = 0x2500,
	DownBorder = 0x2500,
	LeftBorder = 0x2502,
	RightBorder = 0x2502,
	Space = 0x0020
};
enum MAIN_SETT
{
	X = 0,
	Y = 0,
	W = 79,
	H = 24
};

#endif