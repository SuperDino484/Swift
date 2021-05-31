#include "sfpch.h"
#include "EventHandler.h"
#include "Events\KeyEvents.h"


namespace Swift {

	void EventHandler::OnEvent(Event& e)
	{
		EventHandler::HandleEvents<KeyPressedEvent>(e);
		EventHandler::HandleEvents<KeyReleasedEvent>(e);
	}

	template<typename T>
	unsigned int EventHandler::s_HighPriorityIndex = 0;

}