#pragma once

#include "Log.h"

#include <iostream>
#include <memory>



// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
#ifdef _WIN64
	/* Windows x64  */
#define RTA_PLATFORM_WINDOWS
#else
	/* Windows x86 */
#error "x86 Builds are not supported!"
#endif
#else
	/* Unknown compiler/platform */
#error "Unknown platform!"
#endif // End of platform detection
