#pragma once
#include "IGameView.h"
#include "Pipe.h"
//#include "EndGameException.h"
#include <thread>
#include <iostream>

class TowDView : public IGameView
{
	Pipe _p;
public:
	TowDView();
	~TowDView() override;

	virtual void sendMessageToView(const std::string& msg) override;
	virtual std::string getUserInput() override;
};
