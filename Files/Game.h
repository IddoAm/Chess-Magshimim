#pragma once
#include <string>
#include "EndGameException.h"
#include "MoveStatus.h"
#include "Board.h"
#include "Pipe.h"
#include "IGameView.h"
#include "Position.h"
#include <memory>
#include <iostream>

class Game {
public:
	Game(const IGameView& gameView);
	~Game();

	void gameloop();
	int move(std::string instruction);
private:
	Board _board;
	std::unique_ptr<IGameView> gameView;

	int turn;
};
