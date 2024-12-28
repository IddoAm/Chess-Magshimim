#include "Game.h"

Game::Game(std::unique_ptr<IGameView>& gameView)
{
	_turn = 0;
	std::cout << "Game started" << std::endl;
	_gameView = std::move(gameView);
	_gameView->sendMessageToView(_board.toString());

}

void Game::gameloop()
{
	std::string instruction = _gameView->getUserInput();
	while (instruction != "quit")
	{
		move(instruction);
		instruction = _gameView->getUserInput();
	}
}

void Game::move(std::string instruction)
{

	Position from(instruction.substr(0,2)), to(instruction.substr(2,2));
	MoveStatus status = _board.move(from, to, _turn % 2 == 0);

	if (status == MoveStatus::VALID_MOVE ||
		status == MoveStatus::VALID_MOVE_CHECK_OPPONENT ||
		status == MoveStatus::VALID_MOVE_CHECKMATE)
	{
		_turn++;
	}
	
	_gameView->sendMessageToView(std::to_string((int)status));
}
