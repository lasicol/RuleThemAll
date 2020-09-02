#include "Core.h"
#include "Application.h"
#include "Cursor.h"
#include "CursorMonitor.h"
#include "Client.h"

namespace RTA {

	void Application::Run()
	{
		RTA_INFO("Application started!");
		auto monitor = CursorMonitor(CursorApi::Create());


		auto client1 = Client("client1");
		auto client2 = Client("client2");

		// Client test
		auto b1 = HorizontalBoundary();
		b1.maxheight = 1000;
		b1.minheight = 0;
		b1.width = 1920;

		auto b2 = HorizontalBoundary();
		b2.maxheight = 1000;
		b2.minheight = 0;
		b2.width = 0;

		auto n1 = client1.GetNeighboursPtr();
		n1->right = std::pair<Client*, HorizontalBoundary>(&client2, b1);

		auto n2 = client2.GetNeighboursPtr();
		n2->left = std::pair<Client*, HorizontalBoundary>(&client1, b2);

		auto isReached1 = client1.IsBoundaryReached(Position(1920, 50));
		RTA_INFO("isReached: {0}, side: {1}", isReached1.first, isReached1.second);
		auto ptr1 = client1.GetNextClient(isReached1.second);
		RTA_INFO("Client1 right side: {0}", ptr1->GetName());

		auto isReached2 = client2.IsBoundaryReached(Position(0, 50));
		RTA_INFO("isReached: {0}, side: {1}", isReached2.first, isReached2.second);
		auto ptr2 = client2.GetNextClient(BoundarySide::LEFT);
		RTA_INFO("Client2 right side: {0}", ptr2->GetName());

		// ------ 

		while (1) {
			for (long i = 0; i < 99999; i++);
			for (long i = 0; i < 99999; i++);
			monitor.Tick();
		}
	}
}
