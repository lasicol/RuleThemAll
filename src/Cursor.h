#pragma once

#include "Core.h"

namespace RTA {

	struct Position {
		Position(long x, long y) : x(x), y(y) {}
		long x, y;
	};


	class CursorApi
	{
	public:
		virtual ~CursorApi() = default;

		virtual Position inline GetPosition() const = 0;

		static std::unique_ptr<CursorApi> Create();
	};

}

