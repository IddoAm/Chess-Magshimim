#include "Game.h"

Game::Game(std::unique_ptr<IGameView>& p)
{
	this->_gameView = std::move(p);
}

void Game::gameloop()
{
	std::string userInput = "start";
	std::string ans;

	//send the board to the view engine
	ans = this->_board.toString();
	this->_gameView->sendMessageToView(ans);
	//get the user input one time outside the loop so it will be the first turn

	while (userInput != "quit")
	{
		std::cout << "user input" << userInput << std::endl;
		std::cout << "game loop" << std::endl;


		userInput = _gameView->getUserInput();
	}
}

int Game::move(std::string instruction)
{
	return 0;
}


