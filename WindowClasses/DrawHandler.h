#ifndef DRAW_HANDLER
#define DRAW_HANDLER

#include <vector>
using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;

	class DrawHandlerInterface
	{
	protected:
		vector<BasicWindow*> mWindows;
	public:
		void RecursiveAdding(BasicWindow* root);

		virtual void InitDraw() = 0;
		virtual void DrawWindows() = 0;
	};
}

#endif