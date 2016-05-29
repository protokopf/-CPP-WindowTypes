#ifndef INPUT_Manager
#define INPUT_Manager
namespace myconsolewindows
{
	extern class BasicWindow;

	class InputManagerInterface
	{
	protected:
		BasicWindow*& refToCurrentWindowPtr;
	public:
		InputManagerInterface(BasicWindow*& refToCurWinPtr);
		virtual bool Check() = 0;
	};

	// реагирует на следующие клавиши: стрелки, Enter, Escape
	class BasicKeyboardInputManager : public InputManagerInterface
	{

	private:
		void KeyReact(char key);
	public:
		BasicKeyboardInputManager() = default;
		BasicKeyboardInputManager(BasicWindow *& refToAct) : InputManagerInterface(refToAct)
		{

		}

		bool Check() override;
	};
}


#endif