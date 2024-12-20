#pragma once
#include <string>

#include "MoveStatus.h"

#include "Board.h"
#include "GameInterface.h"

#include "Position.h"

class Game {
public:
	Game(std::string gameState = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");

	void gameloop();
	int move(std::string instruction);
private:
	Board board;
	GameInterface gameView;

	int turn;
};
