#include "Game.h"
#include "TowDView.h"

int main()
{
	std::cout << "welcome to the game" << std::endl;
	std::cout << "enter 1 fot tow dimensional view\nenter 2 for three dimensional view" << std::endl;
	//std::unique_ptr<IGameView> p;
	//if (_getch() == '1')
	//{
	//	p = std::make_unique<TowDView>();
	//}
	//else
	//{
	//	//p = std::make_unique<ThreeDView>();
	//}
	//Game game(p);
	////game.gameloop();
}

//// Chess 
//#include "Chess.h"
//
//int main()
//{
//	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
////	string board = "##########K###############################R#############r#r#####";
//	Chess a(board);
//	int codeResponse = 0;
//	string res = a.getInput();
//	while (res != "exit")
//	{
//		/* 
//		codeResponse value : 
//		Illegal movements : 
//		11 - there is not piece at the source  
//		12 - the piece in the source is piece of your opponent
//		13 - there one of your pieces at the destination 
//		21 - illegal movement of that piece 
//		31 - this movement will cause you checkmate
//
//		legal movements : 
//		41 - the last movement was legal and cause check 
//		42 - the last movement was legal, next turn 
//		*/
//
//		/**/ 
//		{ // put your code here instead that code
//			cout << "code response >> ";
//			cin >> codeResponse;
//		}
//		/**/
//
//		a.setCodeResponse(codeResponse);
//		res = a.getInput(); 
//	}
//
//	cout << endl << "Exiting " << endl; 
//	return 0;
//}