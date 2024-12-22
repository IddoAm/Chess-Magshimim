#pragma once
#include <string>

#include "MoveStatus.h"
#include "Board.h"
#include "Pipe.h"
//#include "GameInterface.h"
#include "Position.h"
#include <thread>
#include <iostream>

class Game {
public:
	Game(std::string gameState = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");

	void gameloop();
	int move(std::string instruction);
private:
	Board _board;
	Pipe _p;
	std::string _gameState;
	//GameInterface gameView;
	bool connectToGraphics();

	int turn;
};
