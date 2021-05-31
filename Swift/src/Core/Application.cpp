#include "sfpch.h"
#include "Application.h"

namespace Swift {

	Application::Application()
	{
		SF_CORE_INFO("Application Starting");
		SetEventCallbackFunction(SF_BIND_FN(Application::OnEvent));
		EventSubscriber::AddSubscription<KeyPressedEvent>(SF_BIND_FN(Application::OnKeyEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		KeyPressedEvent e(65);
		m_EventCallbackFunction(e);
		while (true)
		{

		}
	}

	void Application::OnEvent(Event& e)
	{
		SF_CORE_TRACE("{0}", e.GetEventType());
		//EventDispatcher dispatcher(e);
		//dispatcher.DispatchEvent<KeyPressedEvent>(SF_BIND_FN(Application::OnKeyEvent));
		EventHandler::HandleEvents<KeyPressedEvent>(e);
	}


	bool Application::OnKeyEvent(KeyPressedEvent& e)
	{
		SF_CORE_TRACE("KeyEventCall from {0}", e.GetEventType());
		return false;
	}

}