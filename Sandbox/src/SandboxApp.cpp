#include <Swift.h>

class Sandbox : public Swift::Application
{
public:
	Sandbox()
	{
		Swift::EventSubscriber::AddSubscription<Swift::KeyPressedEvent>(SF_BIND_FN(Sandbox::OnKeyEvent));
	}

	~Sandbox()
	{

	}

	bool OnKeyEvent(Swift::KeyPressedEvent& e)
	{
		SF_INFO("{0} called from sandbox", e.GetEventType());
		return false;
	}

private:

};

Swift::Application* Swift::CreateApplication()
{
	return new Sandbox();
}