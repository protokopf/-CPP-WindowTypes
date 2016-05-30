#ifndef WIN_COMMAND
#define WIN_COMMAND

namespace myconsolewindows
{
	extern class BasicWindow;
	extern class ViewLayer;

	class WindowCommand
	{
	protected:
		BasicWindow*& commandedWindow;
	public:
		WindowCommand(BasicWindow*& window) : commandedWindow(window)
		{ 
		}

		virtual void Execute() = 0;
		virtual ~WindowCommand() {}
	};

	class InnerWindowCommand : public WindowCommand
	{
	public:
		InnerWindowCommand() = default;
		InnerWindowCommand(BasicWindow*& goalWindow) : WindowCommand(goalWindow) {}

		void Execute() override;
	};

	class GoToParentWindowCommand : public WindowCommand
	{
	public:
		GoToParentWindowCommand() = default;
		GoToParentWindowCommand(BasicWindow *& goalWindow) : WindowCommand(goalWindow){}

		void Execute() override;
	};
	class GoToNextChildWindowCommand : public WindowCommand
	{
	public:
		GoToNextChildWindowCommand(BasicWindow *& goalWindow) : WindowCommand(goalWindow) {}

		void Execute() override;
	};
	class GoToPrevChildWindowCommand : public WindowCommand
	{
	public:
		GoToPrevChildWindowCommand(BasicWindow *& goalWindow) : WindowCommand(goalWindow) {}

		void Execute() override;
	};

	class LayerMethodWindowCommand : public WindowCommand
	{
	public:
		typedef void(ViewLayer::*ViewLayerMethod)(void);
	private:
		ViewLayer* ptrToLayer = nullptr;
		ViewLayerMethod ptrToMethod = nullptr;
	public:
		LayerMethodWindowCommand(BasicWindow*& window, ViewLayer* lpLayer, ViewLayerMethod lpLayerMethod);

		void Execute() override;
	};
}
#endif