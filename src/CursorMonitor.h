#pragma once

#include "Core.h"
#include "Cursor.h"

namespace RTA {

	class CursorMonitor
	{
	public:
		CursorMonitor(std::unique_ptr<CursorApi> &cursor) : cursor(std::move(cursor)), position(Position(0, 0)) {};
		void Tick();

	private:
		std::unique_ptr<CursorApi> cursor;
		void setCursorPosition();
		Position position;
	};
}

