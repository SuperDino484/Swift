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
}