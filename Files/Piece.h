#pragma once
#include <vector>
#include "Position.h"

class Piece {
public:
	Piece(bool white) : white(white) {}

	virtual std::vector<Position> legalMoves(const Piece* board[8][8]) const = 0;
	virtual	char GetCharRepresentation() const = 0;
protected:
	bool white;
};