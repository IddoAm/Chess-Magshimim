#pragma once

#include <memory>
#include <iostream>
#include "Board.h"
#include "IGameView.h"

class Game {
public:
	Game(std::unique_ptr<IGameView>& gameView);

	void gameloop();
	void move(std::string instruction);
private:
	Board _board;
	std::unique_ptr<IGameView> _gameView;

	int _turn;
};
