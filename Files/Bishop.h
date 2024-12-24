#pragma once
#include "Piece.h"
class Bishop : public Piece {
public:
	Bishop(bool white);
	static std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos, bool white);
	virtual std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};