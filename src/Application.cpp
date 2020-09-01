#include "Core.h"
#include "Application.h"
#include "Cursor.h"
#include "CursorMonitor.h"

namespace RTA {

	void Application::Run()
	{
		RTA_INFO("Application started!");
		auto monitor = CursorMonitor(CursorApi::Create());

		while (1) {
			for (long i = 0; i < 99999; i++);
			for (long i = 0; i < 99999; i++);
			monitor.Tick();
		}
	}
}
