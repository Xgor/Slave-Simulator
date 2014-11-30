#pragma once
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Textbox.h"
//#include "Scenario.h"

class Game
{
public:
	Game();
	~Game();

	bool GameLoop();
	void Update(float deltaTime);
	void Draw();
	void Delete();
	Textbox* getTextbox(){ return m_textbox; };
private:
	sf::RenderWindow* m_window;
	Button* m_exitButton;
	Textbox* m_textbox;
	sf::Clock m_time;
	sf::Vector2i m_mousePos;
	sf::Texture m_texBackground;
	sf::Sprite m_sprBackground;
//	Scenario* m_currentScenario;
};