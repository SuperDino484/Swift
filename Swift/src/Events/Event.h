#pragma once

#include "sfpch.h"
#include "Core/Core.h"

class KeyEvent;

namespace Swift {

	class Event
	{
	public:
		using EventType = std::string;
		virtual EventType GetEventType() = 0;

		void SetIsEventHandled(bool value) { m_IsEventHandled = value; }
		bool GetIsEventHandled() const { return m_IsEventHandled; }

	private:
		bool m_IsEventHandled = false;
	};

	class EventHandler
	{
	public:
		template<typename T>
		static void HandleEvents(Event& e)
		{
			for (auto func : EventSubscriber::EventSubscriptions<T>)
			{
				func(*static_cast<T*>(&e));
			}
		}
	};

	/*class EventDispatcher
	{
		template<typename T>
		using EventCallbackFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e)
			: m_Event(e) {}

		template<typename T>
		void DispatchEvent(EventCallbackFn<T> callback)
		{
			if (m_Event.GetEventType() == T::GetStaticEventType())
			{
				m_Event.SetIsEventHandled(callback(*static_cast<T*>(&m_Event)));
			}
		}

	private:
		Event& m_Event;
	};*/

	class EventSubscriber
	{
	public:
		template<typename T>
		static std::vector<std::function<bool(T&)>> EventSubscriptions;

		template<typename T>
		static void AddSubscription(std::function<bool(T&)> func)
		{
			SF_CORE_INFO("Added event to subscription");
			EventSubscriptions<T>.push_back(func);
			SF_CORE_TRACE("{0}", EventSubscriptions<T>.size());
		}
	};
	
}