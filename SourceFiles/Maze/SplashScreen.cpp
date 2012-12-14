#include "stdafx.h"
#include "SplashScreen.h"
#include "Game.h"

//Display the Backround
void SplashScreen::Show(sf::RenderWindow& window)
{
	sf::Image image;
	image.LoadFromFile("Backgrounds/Splash.png");
	sf::Sprite sprite(image);
	window.Draw(sprite);
	window.Display();

	sf::Event event;

	while (true)
	{
		window.GetEvent(event);

		if(event.Type == sf::Event::Closed)
		{
			Game::SetGameState(dlb::Exiting);
			break;
		}

		//Can Press Escape to exit the Game
		if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
		{
			Game::SetGameState(dlb::Exiting);
			break;
		}

		//Move on if any key or mouse button pressed
		if ((event.Type == sf::Event::KeyPressed && event.Key.Code != sf::Key::Escape) || event.Type == sf::Event::MouseButtonPressed)
			break;
	}
}