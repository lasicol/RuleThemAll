#include "Client.h"


namespace RTA {

	std::pair<bool, BoundarySide> Client::IsBoundaryReached(Position pos)
	{
		auto leftBoundaries = neighbours.left.second;
		if (0 >= pos.x && leftBoundaries.maxheight >= pos.y && pos.y >= leftBoundaries.minheight) {
			return std::pair<bool, BoundarySide>(true, BoundarySide::LEFT);
		}
		auto rightBoundaries = neighbours.right.second;
		if (rightBoundaries.width <= pos.x && rightBoundaries.maxheight >= pos.y && pos.y >= rightBoundaries.minheight) {
			return std::pair<bool, BoundarySide>(true, BoundarySide::RIGHT);
		}
		return std::pair<bool, BoundarySide>(false, BoundarySide::RIGHT);

	}

	Client* Client::GetNextClient(BoundarySide side)
	{
		switch (side)
		{
		case BoundarySide::RIGHT:
			return neighbours.right.first;
		case BoundarySide::LEFT:
			return neighbours.left.first;
		case BoundarySide::TOP:
			throw "Not supported";
		case BoundarySide::BOTTOM:
			throw "Not supported";
		default:
			throw "Not supported";
		}
	}

}
