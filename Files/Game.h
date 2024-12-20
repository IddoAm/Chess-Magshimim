#pragma once
#include <string>

#include "MoveStatus.h"

#include "Board.h"
#include "Position.h"

class Game {
public:
	int move(std::string instruction);


private:
	int turn;

	Position algebraicToPosition(std::string algebraic);
};
