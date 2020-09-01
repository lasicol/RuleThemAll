#include "CursorMonitor.h"

namespace RTA {

	void CursorMonitor::Tick()
	{
		setCursorPosition();
		RTA_INFO("Cursor position is: ({0},{1})", position.x, position.y);
	}

	void CursorMonitor::setCursorPosition()
	{
		position = cursor->GetPosition();
	}

}

