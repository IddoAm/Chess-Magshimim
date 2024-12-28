#include "TowDView.h"

#define MAX_LEN 1024

/*
it start the graphics and connect to it
if the user exit it will throw an exception to end the game
*/
TowDView::TowDView()
{
	bool isConnect = _p.connect();

	std::string ans;
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(500);
			isConnect = _p.connect();
		}
		else
		{
			throw EndGameException("User end the connection");
		}
	}

}

TowDView::~TowDView()
{
	_p.close();
}

void TowDView::sendMessageToView(const std::string& msg)
{
	char msgToGraphics[MAX_LEN];
	strcpy_s(msgToGraphics, msg.c_str());
	_p.sendMessageToGraphics(msgToGraphics);
}

std::string TowDView::getUserInput()
{
	return _p.getMessageFromGraphics();
}


