#include "Scenario.h"
#include <string>

Scenario::Scenario()
{
	m_textbox =m_game.getTextbox();
}


Scenario::~Scenario()
{
}


void Scenario::ShowText(std::string text)
{
	m_textbox->ChangeText(text);

	while (m_textbox->m_inText && m_game.GameLoop())
	{

	}
}