#ifndef WIN_COMMAND
#define WIN_COMMAND

namespace myconsolewindows
{
	extern class BasicWindow;

	class WindowCommand
	{
	protected:
	public:
		virtual void Execute() = 0;
		virtual ~WindowCommand() {}
	};

	class InnerWindowCommand : public WindowCommand
	{
	private:
		BasicWindow* commandedWindow;
	public:
		InnerWindowCommand() = default;
		InnerWindowCommand(BasicWindow* goalWindow);

		void Execute() override;
	};
}
#endif