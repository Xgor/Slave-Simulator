#include "Textbox.h"


Textbox::Textbox()
{

	m_font.loadFromFile("content/fonts/tahoma.ttf");

	m_text.setFont(m_font);
	m_text.setPosition(100, 800);

	m_textboxTexture.loadFromFile("content/textures/TestTextbox.png");
	m_textboxSprite.setTexture(m_textboxTexture);
	m_textboxSprite.setPosition(80, 770);
}



Textbox::~Textbox()
{
}

void Textbox::Draw(sf::RenderWindow * window)
{
	window->draw(m_textboxSprite);
	window->draw(m_text);
}

bool Textbox::Update(float deltaTime)
{
	m_textBoxTimer += deltaTime;


	if (m_drawnText != m_fullText)
	{
		m_drawnText = "";
		for (int i = 0; i < m_textBoxTimer / m_textSpeed; i++)
		{
			m_drawnText += m_fullText[i];
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!spaceDown)
			{
				m_drawnText = m_fullText;
			}
			spaceDown = true;
		}
		else
		{
			spaceDown = false;
		}
		m_text.setString(m_drawnText);
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!spaceDown)
			{
				spaceDown = true;
				return false;
			}
			spaceDown = true;
		}
		else
		{
			spaceDown = false;
		}
	}

	return true;
}



void Textbox::changeText(std::string text)
{
	m_drawnText = "";
	m_fullText = text;
	m_textBoxTimer = 0;

}