#include "Cursor.h"

#ifdef RTA_PLATFORM_WINDOWS
#include "Platform/Windows/CursorWindows.h"
#endif

namespace RTA {

	std::unique_ptr<CursorApi> RTA::CursorApi::Create()
	{
		#ifdef RTA_PLATFORM_WINDOWS
			return std::make_unique<CursorWindows>();
		#endif
		return std::unique_ptr<CursorApi>();
	}
}
