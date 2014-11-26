#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
class Textbox
{
public:
	Textbox();
	~Textbox();

	void Draw(sf::RenderWindow * window);
	bool Update(float deltaTime);
	void setTextSpeed(float speed){ if (speed > 0){ m_textSpeed = speed; }  };
	void changeText(std::string text);

private:

	float m_textSpeed = 0.05;
	float m_textBoxTimer = 0;
	std::string m_drawnText = "";
	std::string m_fullText = "Testing Testing 1 2 3! \nThis thing on?";
	sf::Texture m_textboxTexture;
	sf::Sprite m_textboxSprite;
	sf::Text m_text;
	sf::Font m_font;
	bool spaceDown = "false";
};