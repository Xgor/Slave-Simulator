#include "Game.h"


Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1980, 1080), "SFML works!", sf::Style::Fullscreen);
	m_exitButton = new Button("Exit", 840, 700);
	m_texBackground.loadFromFile("content/textures/Greece-Village-Concept.jpg");
	m_sprBackground.setTexture(m_texBackground);
}


Game::~Game()
{
	
}

void Game::Delete()
{
	delete(m_exitButton);
	delete(m_window);
}

bool Game::GameLoop()
{
	sf::Vector2i mousePos;
	sf::Event event;
	while (m_window->isOpen())
	{
		while (m_window->pollEvent(event))
		{
			
			mousePos = sf::Mouse::getPosition(*m_window);
			
			if (m_exitButton->ButtonFunction(mousePos) || event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_window->close();
			}
		}
		Update(m_time.restart().asSeconds());
		Draw();


	}
	return true;
}

void Game::Update(float deltaTime)
{
	m_textbox->Update(deltaTime);
}

void Game::Draw()
{
	m_window->clear();
//	m_window->draw(shape);
	m_window->draw(m_sprBackground);
	m_textbox->Draw(m_window);
	m_exitButton->Draw(m_window);
	m_window->display();

}