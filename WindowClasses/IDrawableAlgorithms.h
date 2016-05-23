#ifndef IDRAW_ALG
#define IDRAW_ALG

namespace myconsolewindows
{
	extern class BasicWindow;

	class IDrawAlgorithm
	{
	public:
		virtual void Draw(BasicWindow *window) = 0;
		virtual ~IDrawAlgorithm(){}
	};

	class BorderDrawAlgorithm : IDrawAlgorithm
	{
	public:
		void Draw(BasicWindow *window) override;
	};
}
#endif