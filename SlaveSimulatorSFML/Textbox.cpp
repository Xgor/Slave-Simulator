#include "Textbox.h"


Textbox::Textbox()
{
	m_fullText = "NanT434343ext";
	m_font.loadFromFile("content/fonts/tahoma.ttf");

	m_drawnText.setFont(m_font);
	m_drawnText.setPosition(100, 800);

	m_nextLetter.setFont(m_font);
//	m_nextLetter.setPosition(100, 800);

//	m_drawnText.getGlobalBounds().width;

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
	window->draw(m_drawnText);
	window->draw(m_nextLetter);
}

bool Textbox::Update(float deltaTime)
{
	m_textBoxTimer += deltaTime;


	if (m_drawnText.getString() != m_fullText)
	{
		std::string m_tempString = "";
		for (int i = 0; i < m_textBoxTimer / m_textSpeed; i++)
		{
			m_tempString += m_fullText[i];

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!spaceDown)
			{
				m_tempString = m_fullText;
			}
			spaceDown = true;
		}
		else
		{
			spaceDown = false;
		}
		m_drawnText.setString(m_tempString);

//		m_nextLetter.setString( m_fullText[2] );

		sf::FloatRect tempRect = m_drawnText.getGlobalBounds();
	//	m_nextLetter.setColor(sf::Color(255, 255, 255, fmod(m_textBoxTimer,m_textSpeed) * (m_textSpeed / 255)));
//		m_nextLetter.setPosition(tempRect.left + tempRect.width, tempRect.top + tempRect.height);

	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!spaceDown)
			{
				spaceDown = true;
				m_inText = false;
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



void Textbox::ChangeText(std::string text)
{
	m_drawnText.setString("");
	m_fullText = text;
	m_textBoxTimer = 0;
	m_inText = true;
}