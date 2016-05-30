#include "IDrawableAlgorithms.h"
#include "BasicWindow.h"
#include <Windows.h>

namespace myconsolewindows
{
#pragma region ViewAlgorithm

	void ViewAlgorithm::ExtractValuesFromWindow(const BasicWindow *window)
	{
		winPos = window->GetPosition();
		winSize = window->GetSize();
		maxY = winPos.Y + winSize.Y;
		maxX = winPos.X + winSize.X;
		handle = window->GetConsoleHandle();
		color = (WORD)((window->GetBack() << 4) | window->GetFont());
	}

#pragma endregion

#pragma region BorderDrawAlgoruthm
	void BorderDrawAlgorithm::Draw(const BasicWindow *wind)
	{
		ExtractValuesFromWindow(wind);
		LPDWORD length = new DWORD;

		FillConsoleOutputAttribute(handle, color, winSize.X - 1, { winPos.X + 1, winPos.Y }, length);
		FillConsoleOutputAttribute(handle, color, winSize.X - 1, { winPos.X + 1, maxY }, length);

		FillConsoleOutputCharacterW(handle, BORDER::UpBorder, winSize.X - 1, { winPos.X + 1, winPos.Y }, length);
		FillConsoleOutputCharacterW(handle, BORDER::DownBorder, winSize.X - 1, { winPos.X + 1, maxY }, length);

		FillConsoleOutputAttribute(handle, color, 1, winPos, length);
		FillConsoleOutputAttribute(handle, color, 1, { maxX, winPos.Y }, length);
		FillConsoleOutputAttribute(handle, color, 1, { winPos.X, maxY }, length);
		FillConsoleOutputAttribute(handle, color, 1, { maxX, maxY }, length);

		FillConsoleOutputCharacterW(handle, BORDER::LeftUpCorner, 1, winPos, length);
		FillConsoleOutputCharacterW(handle, BORDER::RightUpCorner, 1, { maxX, winPos.Y }, length);
		FillConsoleOutputCharacterW(handle, BORDER::LeftDownCorner, 1, { winPos.X, maxY }, length);
		FillConsoleOutputCharacterW(handle, BORDER::RightDownCorner, 1, { maxX, maxY }, length);

		for (int y = winPos.Y + 1; y < maxY; ++y)
		{
			FillConsoleOutputAttribute(handle, color, 1, { winPos.X, y }, length);
			FillConsoleOutputAttribute(handle, color, 1, { maxX, y }, length);

			FillConsoleOutputCharacterW(handle, BORDER::LeftBorder, 1, { winPos.X, y }, length);
			FillConsoleOutputCharacterW(handle, BORDER::RightBorder, 1, { maxX, y }, length);
		}
		delete length;
	}
#pragma endregion 

#pragma region FillSquareDrawDecorator

	void FillSquareDrawDecorator::FillWindowSquare(const BasicWindow *wind)
	{
		ExtractValuesFromWindow(wind);
		LPDWORD length = new DWORD;
		for (int y = winPos.Y + 1; y < maxY; ++y)
		{
			FillConsoleOutputAttribute(handle, color, winSize.X - 2, { winPos.X + 1, y }, length);
			FillConsoleOutputCharacterW(handle, mFilledSymbol, winSize.X - 2, { winPos.X + 1, y }, length);
		}
		delete length;
	}

#pragma endregion 

#pragma region BorderCleanAlgorithm

	void BorderCleanAlgorithm::Clean(const BasicWindow *window)
	{
		ExtractValuesFromWindow(window);
		LPDWORD length = new DWORD;

		FillConsoleOutputAttribute(handle, color, winSize.X, { winPos.X, winPos.Y }, length);
		FillConsoleOutputAttribute(handle, color, winSize.X, { winPos.X + 1, winPos.Y }, length);

		FillConsoleOutputCharacterW(handle, BORDER::Space, winSize.X, { winPos.X, winPos.Y }, length);
		FillConsoleOutputCharacterW(handle, BORDER::Space, winSize.X, { winPos.X , maxY }, length);

		for (int y = winPos.Y; y < maxY; ++y)
		{
			FillConsoleOutputAttribute(handle, color, winSize.X, { winPos.X, y }, length);
			FillConsoleOutputAttribute(handle, color, winSize.X, { maxX, y }, length);

			FillConsoleOutputCharacterW(handle, BORDER::Space, winSize.X, { winPos.X, y }, length);
			FillConsoleOutputCharacterW(handle, BORDER::Space, winSize.X, { maxX, y }, length);
		}
		delete length;
	}

#pragma endregion
}