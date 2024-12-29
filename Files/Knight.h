#pragma once
#include "Piece.h"

class Knight : public Piece {
	static const int _posibleMoves[8][2];
public:
	Knight(bool white);
	static std::vector<Position> legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos, bool white);
	virtual std::vector<Position> legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};