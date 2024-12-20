#pragma once
#include "Piece.h"

class King : public Piece {
public:
	King(bool white);

	virtual std::vector<Position> legalMoves(const Piece* board[8][8]) const override;
	virtual	char GetCharRepresentation() const override;

	bool underCheck();
	void setCheck(bool check);

private:
	bool check;

};