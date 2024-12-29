#include "King.h"

King::King(bool white)
    : Piece(white)
{
}

std::vector<Position> King::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
	std::vector<Position> moves;
	
	for (size_t i = 0; i < 8; i++)
	{
		if (pos.x + _posibleMoves[i][0] < 0 || pos.x + _posibleMoves[i][0] > 7 || pos.y + _posibleMoves[i][1] < 0 || pos.y + _posibleMoves[i][1] > 7)
		{
			continue;
		}
		if (isPositionSafe(board, Position(pos.x + _posibleMoves[i][0], pos.y + _posibleMoves[i][1])) && (board[pos.x + _posibleMoves[i][0]][pos.y + _posibleMoves[i][1]] == nullptr || board[pos.x + _posibleMoves[i][0]][pos.y + _posibleMoves[i][1]]->isWhite() != this->isWhite()))
		{
			moves.push_back(Position(pos.x + _posibleMoves[i][0], pos.y + _posibleMoves[i][1]));
		}
	}

    return moves;
}


char King::GetCharRepresentation() const
{
    return this->isWhite() ? 'K' : 'k';
}

bool King::isPositionSafe(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
    //check for rooks
    std::vector<Position> moves = Rook::legalMoves(board, pos, this->isWhite());

	for (size_t i = 0; i < moves.size(); i++)
	{
		if (board[moves[i].x][moves[i].y] != nullptr && board[moves[i].x][moves[i].y]->isWhite() != this->isWhite())
		{
			char c = board[moves[i].x][moves[i].y]->GetCharRepresentation();
            if (c == 'r' || c == 'R' || c == 'q' || c == 'Q')
            {
				return false;
            }
		}
	}

    //check for bishops
    moves = Bishop::legalMoves(board, pos, this->isWhite());
    
    for (size_t i = 0; i < moves.size(); i++)
	{
		if (board[moves[i].x][moves[i].y] != nullptr && board[moves[i].x][moves[i].y]->isWhite() != this->isWhite())
		{
			char c = board[moves[i].x][moves[i].y]->GetCharRepresentation();
			if (c == 'b' || c == 'B' || c == 'q' || c == 'Q')
			{
				return false;
			}
		}
	}

    //check for knights
	moves = Knight::legalMoves(board, pos, this->isWhite());
    
    for (size_t i = 0; i < moves.size(); i++)
    {
        if (board[moves[i].x][moves[i].y] != nullptr && board[moves[i].x][moves[i].y]->isWhite() != this->isWhite())
        {
            char c = board[moves[i].x][moves[i].y]->GetCharRepresentation();
            if (c == 'n' || c == 'N')
            {
                return false;
            }
        }
    }

	//check for pawns
	int pawnDirection = this->isWhite() ? 1 : -1;
	if (pos.y + pawnDirection >= 0 && pos.y + pawnDirection <= 7)
	{
		if (pos.x - 1 >= 0)
		{
			if (board[pos.x - 1][pos.y + pawnDirection] != nullptr && board[pos.x - 1][pos.y + pawnDirection]->isWhite() != this->isWhite())
			{
				char c = board[pos.x - 1][pos.y + pawnDirection]->GetCharRepresentation();
				if (c == 'p' || c == 'P')
				{
					return false;
				}
			}
		}
		if (pos.x + 1 <= 7)
		{
			if (board[pos.x + 1][pos.y + pawnDirection] != nullptr && board[pos.x + 1][pos.y + pawnDirection]->isWhite() != this->isWhite())
			{
				char c = board[pos.x + 1][pos.y + pawnDirection]->GetCharRepresentation();
				if (c == 'p' || c == 'P')
				{
					return false;
				}
			}
		}
	}

	return true;
}
