#ifndef I_OBS_H
#define I_OBS_H

#include <list>

//-------Interface-------------
namespace myconsolewindow
{
	template <typename dataType>
	class Subject;

	template<typename dataType>
	class Observer
	{
	private:
		Subject<dataType>* ptrToSubject = nullptr;
	public:
		virtual void UpdateIt(dataType*) = 0;
		void SetSubject(Subject<dataType> *subjPtr);
		void BreakLink();

		virtual ~Observer()
		{
			BreakLink();
		}
	};

	template<typename dataType>
	class Subject
	{
	protected:
		std::list<Observer<dataType>*> observers;
	public:
		void Attach(Observer<dataType> *observer);
	
		void Notify(dataType* data);
		void Break(Observer<dataType> *observer);
	};
}
//-----------------------------


// Observer
namespace myconsolewindow
{
	template <typename dataType>
	void Observer<dataType>::SetSubject(Subject<dataType> *subPtr)
	{
		ptrToSubject = subPtr;
	}

	template<typename dataType>
	void Observer<dataType>::BreakLink()
	{
		ptrToSubject->Break(this);
	}
}

// Subject
namespace myconsolewindow
{
	template<typename dataType>
	void Subject<dataType>::Attach(Observer<dataType> *observer)
	{
		observers.push_back(observer);
		observer->SetSubject(this);
	}

	template<typename dataType>
	void Subject<dataType>::Notify(dataType* data)
	{
		for (auto &obs : observers)
			obs->UpdateIt(data);
	}
	template<typename dataType>
	void Subject<dataType>::Break(Observer<dataType> *observer)
	{
		for (auto iter = observers.begin(); iter != observers.end(); iter++)
		{	
			if (*iter == observer)
			{
				observers.erase(iter);
				break;
			}
		}
	}
}

#endif I_OBS_H;
