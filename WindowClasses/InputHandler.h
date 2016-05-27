#ifndef INPUT_HANDLER
#define INPUT_HANDLER
namespace myconsolewindows
{
	extern class BasicWindow;

	class InputHandlerInterface
	{
	protected:
		BasicWindow*& refToCurrentWindowPtr;
	public:
		InputHandlerInterface(BasicWindow*& refToCurWinPtr);
		virtual bool Check() = 0;
	};

	//class BasicKeyboardInputInterface : public InputHandlerInterface
	//{

	//};
}


#endif