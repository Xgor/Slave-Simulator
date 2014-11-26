#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(std::string text, float xPos, float yPos);
	~Button();

	bool ButtonFunction(sf::Vector2i mousePos);
	void Draw(sf::RenderWindow * window);
private:
	sf::Vector2f m_size = sf::Vector2f(170, 50);
	sf::Vector2f m_pos;
	sf::RectangleShape m_shape;
	sf::FloatRect m_textRect;
	sf::FloatRect m_boundingBox;
	sf::Text m_text;
	sf::Font m_font;

	bool mouseDown;
};