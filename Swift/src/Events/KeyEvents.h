#pragma once
#include "Events/Event.h"

namespace Swift {

	class KeyEvent : public Event
	{
	public:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

	private:
		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode)
			: KeyEvent(keycode) {}

		EventType GetEventType() override
		{
			return GetStaticEventType();
		}

		static EventType GetStaticEventType() { return "KeyPressedEvent"; }

	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		EventType GetEventType() override
		{
			return GetStaticEventType();
		}

		static EventType GetStaticEventType() { return "KeyReleasedEvent"; }

	};

}