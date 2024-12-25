#pragma once
#include <vector>
#include "Position.h"

class Piece {
public:
	Piece(bool white) : _white(white) {}

	bool isWhite() const { return _white; }
	virtual std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos) const = 0;
	virtual	char GetCharRepresentation() const = 0;
	virtual std::vector<Position> warning_moves(const Piece* board[8][8], const Position& pos) const = 0;
protected:
	bool _white;
};