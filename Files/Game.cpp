#include "Game.h"

Game::Game(std::string gameState)
{
	this->_gameState = gameState;
}

Game::~Game()
{
	this->_p.close();
}

void Game::gameloop()
{
	char msgToGraphics[1024];
	std::string msgFromGraphics;

	connectToGraphics();

	//send the board to graphics
	strcpy_s(msgToGraphics, this->_gameState.c_str());
	this->_p.sendMessageToGraphics(msgToGraphics);

	do
	{
		msgFromGraphics = this->_p.getMessageFromGraphics();
	}
	while (msgFromGraphics != "quit");
}

void Game::connectToGraphics()
{
	bool isConnect = this->_p.connect();
	std::string ans;
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(5000);
			isConnect = this->_p.connect();
		}
		else
		{
			throw EndGameException("User end the connection");
		}
	}
}
