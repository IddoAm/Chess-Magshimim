#include "Pawn.h"


Pawn::Pawn(bool white)
	:Piece(white)
{
	this->_isFirstMove = true;
}

std::vector<Position> Pawn::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
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
	if (x +1 < 8 && board[x + 1][y + moveDirection] != nullptr && board[x + 1][y + moveDirection]->isWhite() != this->isWhite())
	{
		moves.push_back(Position(x + 1, y + moveDirection));
	}
	if (x-1 >= 0 && board[x - 1][y + moveDirection] != nullptr && board[x - 1][y + moveDirection]->isWhite() != this->isWhite())
	{
		moves.push_back(Position(x - 1, y + moveDirection));
	}
	return moves;
}

std::vector<Position> Pawn::warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	std::vector<Position> moves;
	int x = pos.x, y = pos.y, moveDirection = this->isWhite() ? 1 : -1;

	//attack
	if (x < 7 && (board[x + 1][y + moveDirection] == nullptr || board[x + 1][y + moveDirection]->isWhite() == this->isWhite()))
	{
		moves.push_back(Position(x + 1, y + moveDirection));
	}
	if (x > 0 && (board[x - 1][y + moveDirection] == nullptr || board[x - 1][y + moveDirection]->isWhite() == this->isWhite()))
	{
		moves.push_back(Position(x - 1, y + moveDirection));
	}
	return moves;
}

char Pawn::GetCharRepresentation() const
{
	return this->isWhite() ? 'P' : 'p';
}
