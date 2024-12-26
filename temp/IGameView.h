#pragma once
#include <string>

class IGameView {
	public:
	virtual ~IGameView();
	virtual void sendMessageToView(const std::string& msg) = 0;
	virtual std::string getUserInput() = 0;
};