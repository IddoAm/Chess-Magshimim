#pragma once
#include "Piece.h"
#include "PawnException.h"

class Pawn : public Piece {
	bool _isFirstMove;
public:
	Pawn(bool white);
	virtual std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};