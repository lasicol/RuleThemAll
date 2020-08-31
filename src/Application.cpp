#include "Core.h"
#include "Application.h"
#include "Cursor.h"

namespace RTA {

	void Application::Run()
	{
		RTA_INFO("Application started!");
		auto cursor = CursorApi::Create();
		Position pos = cursor->GetPosition();
		RTA_INFO("Mouse position: {0}, {1}", pos.x, pos.y);
		while (1) {
			for (long i = 0; i < 99999; i++);
			for (long i = 0; i < 99999; i++);
			Position pos = cursor->GetPosition();
			RTA_INFO("Mouse position: {0}, {1}", pos.x, pos.y);
		}
	}
}
