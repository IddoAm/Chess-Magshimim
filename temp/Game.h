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
	Game(std::unique_ptr<IGameView>& gameView);

	void gameloop();
	int move(std::string instruction);
private:
	Board _board;
	std::unique_ptr<IGameView> _gameView;

	int turn;
};
