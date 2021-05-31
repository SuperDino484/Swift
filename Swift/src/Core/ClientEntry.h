#pragma once
#include "Core/Application.h"
#include "Core/Log.h"

extern Swift::Application* Swift::CreateApplication();

int main(int argc, char** argv)
{
	Swift::Log::Init();
	auto app = Swift::CreateApplication();
	app->Run();
	delete app;

	return 0;
}