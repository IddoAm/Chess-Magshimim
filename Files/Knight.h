#pragma once
#include "Piece.h"

class Knight : public Piece {
	const int _posibleMoves[8][2] = { {1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };
public:
	Knight(bool white);
	virtual std::vector<Position> legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual std::vector<Position> warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};