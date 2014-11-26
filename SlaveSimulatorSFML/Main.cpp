#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Textbox.h"

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1980, 1080), "SFML works!", sf::Style::Fullscreen);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Button exitButton("Exit",840,700);
	Textbox testbox;
	sf::Clock time;

	while (window->isOpen())
	{
		sf::Event event;

		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		
		while (testbox.Update(time.restart().asSeconds()))
		{
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || exitButton.ButtonFunction(mousePos))
				{
					window->close();
					return 0;
				}
			}


			window->clear();
			window->draw(shape);
			testbox.Draw(window);
			exitButton.Draw(window); 
			window->display();

		}
		testbox.changeText("Well it worked well \nThat's really nice to know :) \n ���������");

		while (testbox.Update(time.restart().asSeconds()))
		{
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || exitButton.ButtonFunction(mousePos))
				{
					window->close();
					return 0;
				}
			}


			window->clear(sf::Color(222,222,222));
			window->draw(shape);
			testbox.Draw(window);
			exitButton.Draw(window);
			window->display();

		}
	}

	return 0;
}