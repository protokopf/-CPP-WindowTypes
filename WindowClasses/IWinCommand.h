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
	class GoToChildWindowCommand : public WindowCommand
	{
	public:
		GoToChildWindowCommand() = default;
		GoToChildWindowCommand(BasicWindow *& goalWindow) : WindowCommand(goalWindow){}

		void Execute() override;
	};

	class SlideToNextChildWindowCommand : public WindowCommand
	{
	public:
		SlideToNextChildWindowCommand(BasicWindow *& goalWindow) : WindowCommand(goalWindow) {}

		void Execute() override;
	};
	class SlideToPrevChildWindowCommand : public WindowCommand
	{
	public:
		SlideToPrevChildWindowCommand(BasicWindow *& goalWindow) : WindowCommand(goalWindow) {}

		void Execute() override;
	};
	class SlideToConcreteChildWindowCommand : public WindowCommand
	{
	private:
		int concreteIndex = 0;
	public:
		SlideToConcreteChildWindowCommand(BasicWindow*& refToAct, int index) : WindowCommand(refToAct)
		{
			concreteIndex = index;
		}

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