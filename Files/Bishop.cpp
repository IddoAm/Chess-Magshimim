#include "Bishop.h"

Bishop::Bishop(bool white)
	: Piece(white)
{
}

std::vector<Position> Bishop::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos, bool white)
{
	std::vector<Position> moves;
	int x = pos.x, y = pos.y;

	//up right
	while (x < 8 && y < 8)
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
		y++;
	}

	//up left
	x = pos.x;
	y = pos.y;
	while (x >= 0 && y < 8)
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
		y++;
	}

	//down right
	x = pos.x;
	y = pos.y;
	while (x < 8 && y >= 0)
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
		y--;
	}

	//down left
	x = pos.x;
	y = pos.y;
	while (x >= 0 && y >= 0)
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
		y--;
	}
	return moves;
}

std::vector<Position> Bishop::warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos, bool white)
{
	std::vector<Position> moves;
	int x = pos.x, y = pos.y;

	//up right
	while (x < 8 && y < 8)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() == white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		x++;
		y++;
	}

	//up left
	x = pos.x;
	y = pos.y;
	while (x >= 0 && y < 8)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() == white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		x--;
		y++;
	}

	//down right
	x = pos.x;
	y = pos.y;
	while (x < 8 && y >= 0)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() == white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		x++;
		y--;
	}

	//down left
	x = pos.x;
	y = pos.y;
	while (x >= 0 && y >= 0)
	{
		if (board[x][y] != nullptr)
		{
			if (board[x][y]->isWhite() == white)
			{
				moves.push_back(Position(x, y));
			}
			break;
		}
		moves.push_back(Position(x, y));
		x--;
		y--;
	}
	return moves;
}

std::vector<Position> Bishop::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	return legalMoves(board, pos, this->isWhite());
}

std::vector<Position> Bishop::warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	return warning_moves(board, pos, this->isWhite());
}

char Bishop::GetCharRepresentation() const
{
	return this->isWhite() ? 'B' : 'b';
}
