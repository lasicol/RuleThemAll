#pragma once

#include "Core.h"
#include "Cursor.h"


namespace RTA {
	class Client;

	enum class BoundarySide {
		RIGHT = 0,
		LEFT,
		TOP,
		BOTTOM
	};

	struct VerticalBoundary {
		long maxwidth, minwidth, height;
	};

	struct HorizontalBoundary {
		long width, maxheight, minheight;
	};

	struct Neighbours {
		Neighbours() {
			left = std::pair<Client*, HorizontalBoundary>(nullptr, HorizontalBoundary());
			right = std::pair<Client*, HorizontalBoundary>(nullptr, HorizontalBoundary());
			top = std::pair<Client*, VerticalBoundary>(nullptr, VerticalBoundary());
			bottom = std::pair<Client*, VerticalBoundary>(nullptr, VerticalBoundary());
		}
		std::pair<Client*, HorizontalBoundary> left;
		std::pair<Client*, HorizontalBoundary> right;
		std::pair<Client*, VerticalBoundary> top;
		std::pair<Client*, VerticalBoundary> bottom;
	};


	class Client
	{
	public:
		Client(std::string name)
			: name(name), neighbours() {};
		std::pair<bool, BoundarySide> IsBoundaryReached(Position pos);
		Client* GetNextClient(BoundarySide side);

		std::string inline GetName() { return name; }
		Neighbours* GetNeighboursPtr() { return &neighbours; }
		//void inline SetNeighbours(Neighbours neighbours) { this->neighbours = neighbours; }
		//Boundaries inline GetBoundaries() { return boundaries; }
		//void inline SetBoundaries(Boundaries boundaries) { this->boundaries = boundaries; }
	private:
		std::string name;
		Neighbours neighbours;
	};

}

