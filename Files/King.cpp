#include "King.h"

King::King(bool white)
    : Piece(white)
{
    this->_check = false;
}

std::vector<Position> King::legalMoves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
    bool cantMove[8][8] = { 0 };
    //checking where the king can move
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
		{
            if (board[i][j] != nullptr)
            {
                //cant move because of a team member
                if (board[i][j]->isWhite() == this->isWhite())
				{
					cantMove[i][j] = true;
				}
                //cant move because of checkmate if move
                else
                {
                    std::vector<Position> moves = board[i][j]->warning_moves(board, Position(i, j));

                    for (size_t k = 0; k < moves.size(); k++)
					{
						cantMove[moves[k].x][moves[k].y] = true;
					}
                }
            }
		}
    }
    
    // now check the king moves
    std::vector<Position> moves;
    int x = pos.x, y = pos.y;
    for (size_t i = 0; i < 8; i++)
    {
        if (x + _posibleMoves[i][0] < 0 || x + _posibleMoves[i][0] > 7 || y + _posibleMoves[i][1] < 0 || y + _posibleMoves[i][1] > 7)
		{
			continue;
		}
		if (!cantMove[x + _posibleMoves[i][0]][y + _posibleMoves[i][1]])
		{
			moves.push_back(Position(x + _posibleMoves[i][0], y + _posibleMoves[i][1]));
		}
    }
    return moves;
}

std::vector<Position> King::warning_moves(const std::unique_ptr<Piece> board[8][8], const Position& pos) const
{
    std::vector<Position> moves;

    for (size_t i = 0; i < 8; i++)
	{
        if (pos.x + _posibleMoves[i][0] < 0 || pos.x + _posibleMoves[i][0] > 7 || pos.y + _posibleMoves[i][1] < 0 || pos.y + _posibleMoves[i][1] > 7)
        {
            continue;
        }
		if (board[pos.x + _posibleMoves[i][0]][pos.y + _posibleMoves[i][1]] == nullptr || board[pos.x + _posibleMoves[i][0]][pos.y + _posibleMoves[i][1]]->isWhite() == this->isWhite())
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

//this function check if the move of a temate put the king in check
bool King::moveIsSafe(const std::unique_ptr<Piece> board[8][8], const Position& src, const Position& pos) const
{
    //check where relative they are.
    int dx = src.x - pos.x, dy = src.y - pos.y;

    //if the king himself moved
    if (dx == 0 && dy == 0)
    {
        return true;
    }
    int yDir = 0, xDir = 0;

    //check if it is a diagonal  ++ or --
    if (dx == dy)
    {
        yDir = (dy > 0) ? 1 : -1;
		xDir = (dx > 0) ? 1 : -1;
	}
    //check if it is a diagonal +-
    else if (dx == -dy)
	{
		if (dx > 0)
		{
			yDir = -1;
			xDir = 1;
		}
		else
		{
			yDir = 1;
			xDir = -1;
		}
	}
    //check if vertical
    else if (dx == 0)
    {
		yDir = (dy > 0) ? 1 : -1;
    }
    //check if horizontal
	else if (dy == 0)
	{
		xDir = (dx > 0) ? 1 : -1;
	}
    //no dir
	else
	{
		return true;
	}
    
    // check if the move is safe for the king
    for (int i = 1; i < 8; i++)
    {
        dx += xDir;
        dy += yDir;
        //we got to the end of the board and there is no enemy
        if (dx > 7 || dy > 7 || dx < 0 || dy < 0)
		{
			return true;
		}
		if (board[dx][dy] != nullptr)
		{
            //there is a enemy.
            if (board[dx][dy]->isWhite() != this->isWhite())
			{
                char pieceRep = board[dx][dy]->GetCharRepresentation();
                if (pieceRep == 'Q' || pieceRep == 'q')
                {
					return false;
                }
                if (xDir == 0 || yDir == 0)
                {
                    if (pieceRep == 'R' || pieceRep == 'r')
                    {
						return false;
                    }
                }
                if (pieceRep == 'B' || pieceRep == 'b')
				{
					return false;
				}
			}
            //the piece is not a threat
			return true;
		}
    }
    

}
