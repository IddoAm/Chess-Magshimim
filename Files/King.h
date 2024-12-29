#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

class King : public Piece {
	const int _posibleMoves[8][2] = { {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1} };
public:
	King(bool white);

	virtual std::vector<Position> legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;
	bool isPositionSafe(const std::unique_ptr<Piece> board[8][8], const Position& pos) const;

private:
};