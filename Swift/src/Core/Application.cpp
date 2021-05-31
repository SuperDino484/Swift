#include "sfpch.h"
#include "Application.h"

namespace Swift {

	Application::Application()
	{
		SF_CORE_INFO("Application Starting");
		SetEventCallbackFunction(SF_BIND_FN(Application::OnEvent));
		EventSubscriber::AddSubscription<KeyPressedEvent, EventPriority::Low>(SF_BIND_FN(Application::OnKeyEvent));
		EventSubscriber::AddSubscription<KeyPressedEvent, EventPriority::Low>(SF_BIND_FN(Application::OnKeyEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		KeyPressedEvent e(65);
		EventHandler::OnEvent(e);
		KeyReleasedEvent e1(70);
		EventHandler::OnEvent(e1);
		while (true)
		{

		}
	}

	void Application::OnEvent(Event& e)
	{
		//SF_CORE_TRACE("{0}", e.GetEventType());
		//EventDispatcher dispatcher(e);
		//dispatcher.DispatchEvent<KeyPressedEvent>(SF_BIND_FN(Application::OnKeyEvent));
	}


	bool Application::OnKeyEvent(KeyPressedEvent& e)
	{
		SF_CORE_TRACE("{0} called from Application", e.GetEventType());
		return false;
	}

}