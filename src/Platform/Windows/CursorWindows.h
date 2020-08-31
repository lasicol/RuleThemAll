#pragma once

#include "Cursor.h"

namespace RTA {
	
	class CursorWindows : public CursorApi
	{
		Position GetPosition() const override;
	};

}


