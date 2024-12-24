#include "Queen.h"

Queen::Queen(bool white)
	: Piece(white)
{
}

std::vector<Position> Queen::legalMoves(const Piece* board[8][8], const Position& pos) const
{
	std::vector<Position> RookMoves = Rook::legalMoves(board, pos, this->isWhite());
	std::vector<Position> BishopMoves = Bishop::legalMoves(board, pos, this->isWhite());
	RookMoves.insert(RookMoves.end(), BishopMoves.begin(), BishopMoves.end());
	return RookMoves;
}

char Queen::GetCharRepresentation() const
{
	return this->isWhite() ? 'Q' : 'q';
}


