#pragma once

struct Position {
public:
	unsigned int x;
	unsigned int y;
	
	Position() {x = 0; y = 0;}
	Position(int x, int y)
		: x(x), y(y) {}

};