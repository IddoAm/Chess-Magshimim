#pragma once
#include "Piece.h"
class Rook : public Piece {
public:
	Rook(bool white);
	static std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos, bool white);
	static std::vector<Position> warning_moves(const Piece* board[8][8], const Position& pos, bool white);
	virtual std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos) const override;
	virtual std::vector<Position> warning_moves(const Piece* board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
};