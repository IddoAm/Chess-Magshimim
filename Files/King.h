#pragma once
#include "Piece.h"

class King : public Piece {
	const int _posibleMoves[8][2] = { {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1} };
public:
	King(bool white);

	virtual std::vector<Position> legalMoves(const Piece* board[8][8], const Position& pos) const override;
	virtual std::vector<Position> warning_moves(const Piece* board[8][8], const Position& pos) const override;
	virtual	char GetCharRepresentation() const override;

	bool moveIsSafe(const Piece* board[8][8], const Position& src, const Position& pos) const;
	bool underCheck() const { return _check; }
	void setCheck(bool check) { _check = check; }

private:
	bool _check;

};