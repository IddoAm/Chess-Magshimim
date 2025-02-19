#pragma once

enum class MoveStatus {
    VALID_MOVE,
    VALID_MOVE_CHECK_OPPONENT,
    INVALID_MOVE_NO_PLAYER_PIECE,
    INVALID_MOVE_KING_UNDER_CHECK, //because it will never happpen i change it to my need. src = INVALID_MOVE_SAME_PLAYER_PIECE, i made it = INVALID_MOVE_KING_UNDER_CHECK
    INVALID_MOVE_CHECK_CURRENT,
    INVALID_MOVE_ILLEGAL_INDEX,
    INVALID_MOVE_ILLEGAL_PIECE_MOVE,
    INVALID_MOVE_SAME_SQUARE,
    VALID_MOVE_CHECKMATE
};