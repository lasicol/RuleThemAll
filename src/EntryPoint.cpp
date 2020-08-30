#include "Application.h"
#include "Log.h"


	int main() {

		RTA::Log::Init();

		auto app = new RTA::Application();
		app->Run();
		delete app;
	}

