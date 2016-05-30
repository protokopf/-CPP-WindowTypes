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
		vector<BasicWindow*>& refToAllWindows;
	public:
		DrawManagerInterface(BasicWindow* root, vector<BasicWindow*>& refToVector) : refToAllWindows(refToVector)
		{

		}
		virtual void InitDraw() = 0;
		virtual void DrawWindows() = 0;
	};

	class WindowDrawManager : public DrawManagerInterface
	{
	public:
		WindowDrawManager(BasicWindow *window, vector<BasicWindow*>& refToVector) : DrawManagerInterface(window,refToVector)
		{
		}

		void InitDraw() override;
		void DrawWindows() override;
	};
}

#endif