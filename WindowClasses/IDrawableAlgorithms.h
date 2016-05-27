#ifndef IDRAW_ALG
#define IDRAW_ALG

#include <iostream>
#include <vector>

using namespace std;
namespace myconsolewindows
{
	extern class BasicWindow;

	class IDrawAlgorithm
	{
	protected:
		COORD winPos;
		COORD winSize;
		int maxY;
		int maxX;
		HANDLE handle;
		WORD   color;
		
		void ExtractValuesFromWindow(BasicWindow *window);
	public:
		virtual void Draw(BasicWindow *window) = 0;
		virtual ~IDrawAlgorithm(){}
	};

	class ADrawDecorator : public IDrawAlgorithm
	{
	private: 
		IDrawAlgorithm *component;
	public:
		ADrawDecorator(IDrawAlgorithm *dAlgorithm) : component(dAlgorithm)
		{

		}
		void Draw(BasicWindow *window)
		{
			component->Draw(window);
		}
	};

	class FillSquareDrawDecorator : ADrawDecorator
	{
	private:
		void FillWindowSquare(BasicWindow *window);
		wchar_t mFilledSymbol;
	public:
		FillSquareDrawDecorator(wchar_t fillingSymbol, IDrawAlgorithm *algorithm) : ADrawDecorator(algorithm)
		{
			mFilledSymbol = fillingSymbol;
		}

		void Draw(BasicWindow* window)
		{
			ADrawDecorator::Draw(window);
			FillWindowSquare(window);
		}
	};

	class BorderDrawAlgorithm : IDrawAlgorithm
	{
	private:
	public:
		void Draw(BasicWindow *window) override;

		~BorderDrawAlgorithm();
	};
}
#endif