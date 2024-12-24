#include "Pawn.h"


Pawn::Pawn(bool white)
	:Piece(white)
{
	this->_isFirstMove = true;
}

std::vector<Position> Pawn::legalMoves(const Piece* board[8][8], const Position& pos) const
{
	if (pos.y == 0 || pos.y == 7)
	{
		throw PawnException(); //when the pawn is in the end so it will transform to queen
	}
	std::vector<Position> moves;
	int x = pos.x, y = pos.y, moveDirection = this->isWhite() ? 1 : -1;

	//regular move
	if (board[x][y + moveDirection] == nullptr)
	{
		moves.push_back(Position(x, y + moveDirection));
	}

	//first move
	if (this->_isFirstMove)
	{
		if (board[x][y + (2 * moveDirection)] == nullptr)
		{
			moves.push_back(Position(x, y + (2 * moveDirection)));
		}
	}

	//attack
	if (board[x + 1][y + moveDirection] != nullptr && board[x + 1][y + moveDirection]->isWhite() != this->isWhite())
	{
		moves.push_back(Position(x + 1, y + moveDirection));
	}
	if (board[x - 1][y + moveDirection] != nullptr && board[x - 1][y + moveDirection]->isWhite() != this->isWhite())
	{
		moves.push_back(Position(x - 1, y + moveDirection));
	}
}

char Pawn::GetCharRepresentation() const
{
	return this->isWhite() ? 'P' : 'p';
}
