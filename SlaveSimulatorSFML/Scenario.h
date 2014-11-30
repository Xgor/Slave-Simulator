#pragma once

#include <iostream>
#include "Textbox.h"
#include "Game.h"
class Scenario
{
public:
	Scenario();
	virtual ~Scenario();

	virtual void scenarioEvents() = 0;

protected:
	void ShowText(std::string text);
	void ChangeBackground();
	
	int ShowChoices(std::string choice1, std::string choice2, std::string choice3, std::string choice4);
private:
	Game m_game;
	Textbox* m_textbox;
};

