#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_board[i][j] = nullptr;
		}
	}
	//set the white side
	_board[0][0] = std::make_unique<Rook>(true);
	_board[1][0] = std::make_unique<Knight>(true);
	_board[2][0] = std::make_unique<Bishop>(true);
	_board[3][0] = std::make_unique<Queen>(true);
	_board[4][0] = std::make_unique<King>(true);
	_board[5][0] = std::make_unique<Bishop>(true);
	_board[6][0] = std::make_unique<Knight>(true);
	_board[7][0] = std::make_unique<Rook>(true);
	//set the black side
	_board[0][7] = std::make_unique<Rook>(false);
	_board[1][7] = std::make_unique<Knight>(false);
	_board[2][7] = std::make_unique<Bishop>(false);
	_board[3][7] = std::make_unique<Queen>(false);
	_board[4][7] = std::make_unique<King>(false);
	_board[5][7] = std::make_unique<Bishop>(false);
	_board[6][7] = std::make_unique<Knight>(false);
	_board[7][7] = std::make_unique<Rook>(false);

	//make the pawns
	for (int i = 0; i < 8; i++)
	{
		_board[i][1] = std::make_unique<Pawn>(true);
		_board[i][6] = std::make_unique<Pawn>(false);
	}

	_kingPositions[0] = Position(4, 0);
	_kingPositions[1] = Position(4, 7);
}

std::string Board::toString()
{
	std::string boardString = "";
	for (int y = 7; y >= 0; y--)
	{
		for (int x = 0; x < 8; x++)
		{
			if (_board[x][y] == nullptr)
			{
				boardString += '#';
			}
			else
			{
				boardString += _board[x][y]->GetCharRepresentation();
			}
		}
	}
	boardString += "0";
	return boardString;
}

MoveStatus Board::move(Position src, Position dst, bool whiteTurn)
{
	//check if the move is in the board
	if (src.x < 0 || src.x > 7 || src.y < 0 || src.y > 7 || dst.x < 0 || dst.x > 7 || dst.y < 0 || dst.y > 7)
	{
		return MoveStatus::INVALID_MOVE_ILLEGAL_INDEX;
	}
	//check if it can move the piece
	if (_board[src.x][src.y] == nullptr)
	{
		return MoveStatus::INVALID_MOVE_NO_PLAYER_PIECE;
	}
	//a refrence so i will not need to type all the code evrey time
	const std::unique_ptr<Piece>& pieceRef = _board[src.x][src.y];

	if (pieceRef->isWhite() != whiteTurn)
	{
		return MoveStatus::INVALID_MOVE_NO_PLAYER_PIECE;
	}

	//get refrence to the king
	//check if the move is not in the moves
	std::vector<Position> moves = pieceRef->legalMoves(_board, src);
	if (std::find(moves.begin(), moves.end(), dst) == moves.end())
	{
		return MoveStatus::INVALID_MOVE_ILLEGAL_PIECE_MOVE;
	}

	if (src == dst)
	{
		return MoveStatus::INVALID_MOVE_SAME_SQUARE;
	}

	King& kingRef = dynamic_cast<King&>(*_board[_kingPositions[!whiteTurn].x][_kingPositions[!whiteTurn].y]);
	
	//check if the move not create a check on team king
	if (kingRef.moveIsSafe(_board, src, _kingPositions[!whiteTurn]) == false)
	{
		return MoveStatus::INVALID_MOVE_CHECK_CURRENT;
	}


	//the move is valid
	
	// checking if the king is under a check
	std::unique_ptr<Piece> temp = nullptr;
	if (_board[dst.x][dst.y] != nullptr)
	{
		temp = std::move(_board[dst.x][dst.y]);
	}
	_board[dst.x][dst.y] = std::move(_board[src.x][src.y]);
	_board[src.x][src.y] = nullptr;
	//check if king is steel in check
	if (kingRef.underCheck(_board, _kingPositions[!whiteTurn]))
	{
		_board[src.x][src.y] = std::move(_board[dst.x][dst.y]);
		_board[dst.x][dst.y] = std::move(temp);
		return MoveStatus::INVALID_MOVE_KING_UNDER_CHECK;
	}

	// now checking if it create a check
	moves = _board[dst.x][dst.y]->legalMoves(_board, dst);
	if (std::find(moves.begin(), moves.end(), _kingPositions[whiteTurn]) != moves.end())
	{
		//check if it a checkmate
		if (_board[_kingPositions[whiteTurn].x][_kingPositions[whiteTurn].y]->legalMoves(_board, _kingPositions[whiteTurn]).size() == 0)
		{
			return MoveStatus::VALID_MOVE_CHECKMATE;
		}
		else
		{
			dynamic_cast<King&>(*_board[_kingPositions[whiteTurn].x][_kingPositions[whiteTurn].y]).setCheck(dst);
			return MoveStatus::VALID_MOVE_CHECK_OPPONENT;
		}
	}
	if (src == _kingPositions[!whiteTurn])
	{
		_kingPositions[!whiteTurn] = dst;
	}
	//TODO: add check if the Pawn is a promotion
	return MoveStatus::VALID_MOVE;
	
}
