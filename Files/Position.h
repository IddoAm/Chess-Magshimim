#pragma once
#include <string>

struct Position {
public:
	unsigned int x;
	unsigned int y;
	
	Position() {x = 0; y = 0;}
	Position(std::string pos)
	{
		for (int i = 0; i < 2; i++)
		{
			if (pos[i] >= 'a' && pos[i] <= 'h')
			{
				x = pos[i] - 'a';
			}
			else if (pos[i] >= '1' && pos[i] <= '8')
			{
				y = pos[i] - '1';
			}
		}
	}
	Position(int x, int y)
		: x(x), y(y) {}

	//operators
	bool operator==(const Position& other) const { return x == other.x && y == other.y; }

};