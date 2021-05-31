#include <Swift.h>

class Sandbox : public Swift::Application
{
public:
	Sandbox()
	{
		Swift::EventSubscriber::AddSubscription<Swift::KeyPressedEvent, Swift::EventPriority::High>(SF_BIND_FN(Sandbox::OnKeyEvent));
		Swift::EventSubscriber::AddSubscription<Swift::KeyReleasedEvent, Swift::EventPriority::High>(SF_BIND_FN(Sandbox::OnKeyReleasedEvent));
	}

	~Sandbox()
	{

	}

	bool OnKeyReleasedEvent(Swift::KeyReleasedEvent& e)
	{
		SF_TRACE("KeyReleasedEvent called");
		return false;
	}

	bool OnKeyEvent(Swift::KeyPressedEvent& e)
	{
		SF_TRACE("{0} called from Sandbox", e.GetEventType());
		return false;
	}

private:

};

Swift::Application* Swift::CreateApplication()
{
	return new Sandbox();
}