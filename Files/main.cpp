#include <iostream>
#include "TowDView.h"

int main()
{
	std::cout << "welcome to the game" << std::endl;
	std::cout << "enter 1 fot tow dimensional view\nenter 2 for three dimensional view" << std::endl;
	std::unique_ptr<IGameView> p;
	if (_getch() == '1')
	{
		p = std::make_unique<TowDView>();
		p->sendMessageToView("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	}
	else
	{
		//p = std::make_unique<ThreeDView>();
	}
	//Game game(p);
	//game.gameloop();
}