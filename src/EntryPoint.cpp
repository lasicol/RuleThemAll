#include "Core.h"
#include "Application.h"

	int main() {

		RTA::Log::Init();

		auto app = new RTA::Application();
		app->Run();
		delete app;
	}

