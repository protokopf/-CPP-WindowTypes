#include "IDrawableAlgorithms.h"
#include "BasicWindow.h"
#include <Windows.h>

namespace myconsolewindows
{

	//BorderDrawAlgorithm

	// переписать алгоритм так, чтобы цикл проходился только по границе
	void BorderDrawAlgorithm::Draw(BasicWindow *wind)
	{
		COORD winPos = wind->GetPosition();
		COORD winSize = wind->GetSize();
		int maxY = winPos.Y + winSize.Y;
		int maxX = winPos.X + winSize.X;
		for (int i = winPos.Y; i < maxY; ++i)
		{
			for (int j = winPos.X; j < maxX; ++j)
			{
				char symbol;
				SetConsoleCursorPosition(wind->GetConsoleHandle(), { j, i });
				if (i == winPos.Y && j == winPos.X)
					symbol = BORDER::LeftUpCorner;
				else if (i == winPos.Y && j == maxX - 1)
					symbol = BORDER::RightUpCorner;
				else if (i == maxY - 1 && j == winPos.X)
					symbol = BORDER::LeftDownCorner;
				else if (i == maxY - 1 && j == maxX - 1)
					symbol = BORDER::RightDownCorner;
				else if ((i == winPos.Y || i == maxY - 1) && j > winPos.X)
					symbol = BORDER::UpBorder;
				else if (i > winPos.Y && (j == winPos.X || j == maxX - 1))
					symbol = BORDER::LeftBorder;
				else
				{
	
					continue;
				}
				Console.Write(symbol);
			}
		}
	}

}