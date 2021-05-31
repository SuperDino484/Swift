#pragma once
#include "Core/Core.h"
#include "Events/Event.h"
#include "Events/KeyEvents.h"

namespace Swift {

	class Application
	{
		using EventCallbackFn = std::function<void(Event&)>;
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		bool OnKeyEvent(KeyPressedEvent& e);

		void SetEventCallbackFunction(EventCallbackFn callback) { m_EventCallbackFunction = callback; }

	private:
		EventCallbackFn m_EventCallbackFunction;
	};

	Application* CreateApplication();

}
