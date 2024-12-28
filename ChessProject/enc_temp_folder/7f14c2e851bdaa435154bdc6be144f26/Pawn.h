#pragma once
#include "Piece.h"

class Pawn : public Piece {
	bool _isFirstMove;
public:
	Pawn(bool white);
	virtual std::vector<Position> legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual std::vector<Position> warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};