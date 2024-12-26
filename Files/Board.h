#pragma once

#define SIZE 8

#include <string>
#include <memory>

#include "MoveStatus.h"

#include "Position.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

class Board {
public:
    Board();

    std::string toString();
    MoveStatus move(Position src, Position dst, bool whiteTurn);

private:
    std::unique_ptr<Piece> _board[8][8];
    Position _kingPositions[2];
};
