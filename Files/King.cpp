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
		if (!cantMove[x + _posibleMoves[i][0]][y + _posibleMoves[i][1]])
		{
			moves.push_back(Position(x + _posibleMoves[i][0], y + _posibleMoves[i][1]));
		}
    }
    return moves;
}

char King::GetCharRepresentation() const
{
    return this->isWhite() ? 'K' : 'k';
}
