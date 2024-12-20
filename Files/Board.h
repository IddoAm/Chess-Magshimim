#pragma once

#define SIZE 8

#include <string>
#include <memory>

#include "MoveStatus.h"

#include "Position.h"
#include "Piece.h"
#include "King.h"

class Board {
public:
    Board();

    std::string toString();
    MoveStatus move(Position src, Position dst);

private:
    std::unique_ptr<Piece> board[8][8];
    King* whiteKing, blackKing;
};
