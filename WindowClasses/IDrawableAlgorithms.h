#ifndef IDRAW_ALG
#define IDRAW_ALG

#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;
namespace myconsolewindows
{
	extern class BasicWindow;

	class ViewAlgorithm
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
		virtual ~ViewAlgorithm() {}
	};

	class IDrawAlgorithm : public ViewAlgorithm
	{
	public:
		virtual void Draw(BasicWindow *window) = 0;
		virtual ~IDrawAlgorithm() {}
	};
	class BorderDrawAlgorithm : public IDrawAlgorithm
	{
	public:
		void Draw(BasicWindow *window) override;
		virtual ~BorderDrawAlgorithm(){}
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
		virtual ~ADrawDecorator()
		{
			delete component;
		}
	};
	class FillSquareDrawDecorator : public ADrawDecorator
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
		virtual ~FillSquareDrawDecorator(){}
	};

	class ICleanAlgorithm : public ViewAlgorithm
	{
	public:
		virtual void Clean(BasicWindow *window) = 0;
		virtual ~ICleanAlgorithm(){}
	};
	class BorderCleanAlgorithm : public ICleanAlgorithm
	{
	public:
		void Clean(BasicWindow *window) override;
	};
}
#endif