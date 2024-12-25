#include "King.h"

King::King(bool white)
    : Piece(white)
{
    this->_check = false;
}

std::vector<Position> King::legalMoves(const Piece* board[8][8], const Position& pos) const
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

std::vector<Position> King::warning_moves(const Piece* board[8][8], const Position& pos) const
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
