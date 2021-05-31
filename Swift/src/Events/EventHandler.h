#pragma once
#include "Event.h"

namespace Swift {


	class EventHandler
	{
	public:
		template<typename T>
		static void HandleEvents(Event& e)
		{
			for (auto func : s_EventSubscriptionsList<T>)
			{
				if (e.GetEventType() == T::GetStaticEventType())
				{
					func(*static_cast<T*>(&e));
				}
			}
			SF_CORE_INFO("Size: {0}", s_EventSubscriptionsList<T>.size());
		}

		static void OnEvent(Event& e);

		template<typename T>
		static void PushLowPriority(std::function<bool(T&)> func)
		{
			s_EventSubscriptionsList<T>.emplace_back(func);
		}

		template<typename T>
		static void PushHighPriority(std::function<bool(T&)> func)
		{
			s_EventSubscriptionsList<T>.emplace(EventHandler::s_EventSubscriptionsList<T>.begin() + s_HighPriorityIndex<T>, func);
			s_HighPriorityIndex<T>++;
		}

	public:
		template<typename T>
		static unsigned int s_HighPriorityIndex;

		template<typename T>
		static std::vector<std::function<bool(T&)>> s_EventSubscriptionsList;
	};

	template<typename T>
	std::vector<std::function<bool(T&)>> EventHandler::s_EventSubscriptionsList;


}

