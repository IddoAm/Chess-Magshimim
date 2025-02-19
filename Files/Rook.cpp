#include "Rook.h"

Rook::Rook(bool white)
	: Piece(white)
{
}

std::vector<Position> Rook::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos, bool white)
{
	std::vector<Position> moves;
	int x = pos.x, y = pos.y;

	y = y + 1;
	//up
	while (y < 8)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() != white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		y++;
	}

	//down
	y = pos.y - 1;
	while (y >= 0)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() != white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		y--;
	}

	//right
	y = pos.y;
	x = x + 1;
	while (x < 8)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() != white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		x++;
	}

	//left
	x = pos.x - 1;
	while (x >= 0)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() != white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		x--;
	}

	return moves;
}

std::vector<Position> Rook::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	return legalMoves(board, pos, this->isWhite());
}

char Rook::GetCharRepresentation() const
{
	return this->isWhite() ? 'R' : 'r';
}
