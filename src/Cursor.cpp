#include "Cursor.h"

#ifdef RTA_PLATFORM_WINDOWS
#include "Platform/Windows/CursorWindows.h"
#endif

namespace RTA {

	Scope<CursorApi> RTA::CursorApi::Create()
	{
		#ifdef RTA_PLATFORM_WINDOWS
			return CreateScope<CursorWindows>();
		#endif
		return Scope<CursorApi>();
	}
}
