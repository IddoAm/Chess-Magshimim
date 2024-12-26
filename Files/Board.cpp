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

	//check if the move not create a check on team king
	const King& kingRef = static_cast<const King&>(_board[_kingPositions[!whiteTurn].x][_kingPositions[!whiteTurn].y].get());
	if (kingRef.moveIsSafe(_board, src, _kingPositions[!whiteTurn]) == false)
	{
		return MoveStatus::INVALID_MOVE_CREATE_CHECK;
	}

}
