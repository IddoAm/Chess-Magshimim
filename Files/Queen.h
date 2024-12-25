#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Piece
{
public:
	Queen(bool white);
	virtual std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos) const override;
	virtual std::vector<Position> warning_moves(const Piece* board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};