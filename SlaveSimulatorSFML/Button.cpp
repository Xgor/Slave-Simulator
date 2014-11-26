#include "Button.h"


Button::Button(std::string text, float xPos, float yPos)
{

	m_font.loadFromFile("content/fonts/tahoma.ttf");

	m_pos = sf::Vector2f(xPos, yPos);
	m_shape = sf::RectangleShape(m_size);
	m_shape.setPosition(m_pos);
	m_shape.setOutlineThickness(1);
	m_shape.setOutlineColor(sf::Color(100, 100, 100));
	m_boundingBox = m_shape.getGlobalBounds();

	m_text.setFont(m_font);
	m_text.setString(text);



	m_textRect = m_shape.getGlobalBounds();
	m_text.setPosition(m_textRect.left + m_textRect.width / 2.0f,
		m_textRect.top + m_textRect.height / 2.0f);

	m_textRect = m_text.getLocalBounds();
	m_text.setOrigin(m_textRect.left + m_textRect.width / 4.0f,
		m_textRect.top + m_textRect.height / 4.0f);

	m_text.setCharacterSize(16);
	m_text.setColor(sf::Color::Black);



}


Button::~Button()
{
}

bool Button::ButtonFunction(sf::Vector2i mousePos)
{

	if (m_boundingBox.contains(mousePos.x, mousePos.y))
	{

		m_shape.setFillColor(sf::Color(200, 200, 200));
		if (!mouseDown && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true;
		}
	}
	else
	{
		m_shape.setFillColor(sf::Color::White);
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseDown = true;
	}
	else
	{
		mouseDown = false;
	}

	return false;
}

void Button::Draw(sf::RenderWindow * window)
{
	window->draw(m_shape);
	window->draw(m_text);
}