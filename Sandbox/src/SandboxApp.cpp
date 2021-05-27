#include <Swift.h>

class Sandbox : public Swift::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

private:

};

Swift::Application* Swift::CreateApplication()
{
	return new Sandbox();
}