#ifndef DRAW_Manager
#define DRAW_Manager

#include <vector>
using namespace std;

namespace myconsolewindows
{
	extern class BasicWindow;

	class DrawManagerInterface
	{
	protected:
		vector<BasicWindow*> mWindows;
	public:
		void RecursiveAdding(BasicWindow* root);

		virtual void InitDraw() = 0;
		virtual void DrawWindows() = 0;
	};

	class WindowDrawManager : public DrawManagerInterface
	{
	public:
		WindowDrawManager(BasicWindow *window) 
		{
			RecursiveAdding(window);
		}

		void InitDraw() override;
		void DrawWindows() override;
	};
}

#endif