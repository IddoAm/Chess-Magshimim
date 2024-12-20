#pragma once

#define SIZE 8

#include <string>
#include <memory>

#include "Position.h"
#include "Piece.h"
#include "King.h"

enum class MoveStatus {
    VALID_MOVE,
    VALID_MOVE_CHECK_OPPONENT,
    INVALID_MOVE_NO_PLAYER_PIECE,
    INVALID_MOVE_SAME_PLAYER_PIECE,
    INVALID_MOVE_CHECK_CURRENT,
    INVALID_MOVE_ILLEGAL_INDEX,
    INVALID_MOVE_ILLEGAL_PIECE_MOVE,
    INVALID_MOVE_SAME_SQUARE,
    VALID_MOVE_CHECKMATE
};


class Board {
public:
    Board();

    std::string toString();
    MoveStatus move(Position src, Position dst);

private:
    std::unique_ptr<Piece> board[8][8];
    King* whiteKing, blackKing;
};
