#include <iostream>
#include "TowDView.h"
#include "Game.h"

int main()
{
	std::cout << "welcome to the game" << std::endl;
	std::cout << "enter 1 fot tow dimensional view\nenter 2 for three dimensional view" << std::endl;
	std::unique_ptr<IGameView> p;
	if (_getch() == '1')
	{
		try
		{
			p = std::make_unique<TowDView>();
		}
		catch (EndGameException& e)
		{
			std::cout << e.what() << std::endl;
			return 1;
		}
	}
	else
	{
		//p = std::make_unique<ThreeDView>();
	}
	Game game(p);
	game.gameloop();

	return 0;
}