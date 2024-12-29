#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Piece
{
public:
	Queen(bool white);
	virtual std::vector<Position> legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};