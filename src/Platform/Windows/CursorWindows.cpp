#include <Windows.h>

#include "CursorWindows.h"

namespace RTA {
	
	Position CursorWindows::GetPosition() const
	{
		POINT p;
		GetCursorPos(&p);
		return Position(p.x, p.y);
	}

}

