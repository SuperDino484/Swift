#pragma once


namespace Swift {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();


	private:

	};

	Application* CreateApplication();

}
