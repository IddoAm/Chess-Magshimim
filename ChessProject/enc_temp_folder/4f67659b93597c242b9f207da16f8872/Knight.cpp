#include "Knight.h"

Knight::Knight(bool white)
	: Piece(white)
{
}

std::vector<Position> Knight::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	std::vector<Position> moves;
	int posibleMoves[8][2] = { {1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };
	int x = pos.x, y = pos.y;

	for (size_t i = 0; i < 8; i++)
	{
		if (x + posibleMoves[i][0] < 0 || x + posibleMoves[i][0] > 7 || y + posibleMoves[i][1] < 0 || y + posibleMoves[i][1] > 7)
		{
			continue;
		}
		if (board[x + posibleMoves[i][0]][y + posibleMoves[i][1]] == nullptr)
		{
			moves.push_back(Position(x + posibleMoves[i][0], y + posibleMoves[i][1]));
		}
		else if (board[x + posibleMoves[i][0]][y + posibleMoves[i][1]]->isWhite() != this->isWhite())
		{
			moves.push_back(Position(x + posibleMoves[i][0], y + posibleMoves[i][1]));
		}
	}

	return moves;
}

std::vector<Position> Knight::warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	std::vector<Position> moves;
	int x = pos.x, y = pos.y;
	
	for (size_t i = 0; i < 8; i++)
	{
		if (board[x + _posibleMoves[i][0]][y + _posibleMoves[i][1]] == nullptr)
		{
			moves.push_back(Position(x + _posibleMoves[i][0], y + _posibleMoves[i][1]));
		}
		else if (board[x + _posibleMoves[i][0]][y + _posibleMoves[i][1]]->isWhite() == this->isWhite())
		{
			moves.push_back(Position(x + _posibleMoves[i][0], y + _posibleMoves[i][1]));
		}
	}

	return moves;
}

char Knight::GetCharRepresentation() const
{
	return this->isWhite() ? 'N' : 'n';
}
