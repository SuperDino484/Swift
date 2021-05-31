#pragma once
#include "EventHandler.h"


namespace Swift {

	enum class EventPriority
	{
		None = 0,
		Low, High
	};

	class EventSubscriber
	{
	public:
		template<typename T, EventPriority P>
		static void AddSubscription(std::function<bool(T&)> func)
		{
			SF_CORE_INFO("Added {0} to subscription with priority {1}", T::GetStaticEventType(), P);
			switch (P)
			{
			case EventPriority::None:
				break;
			case EventPriority::Low:
			{
				EventHandler::PushLowPriority<T>(func);
				break;
			}
			case EventPriority::High:
			{
				EventHandler::PushHighPriority<T>(func);
				break;
			}
			}
			//EventHandler::s_EventSubscriptionsList<T>.push_back(func);
		}
	private:
	};
}

