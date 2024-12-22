#include "Game.h"

Game::Game(std::string gameState)
{
	this->_gameState = gameState;
}

void Game::gameloop()
{
	
}

bool Game::connectToGraphics()
{
	bool isConnect = p.connect();
	std::string ans;
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}
}
