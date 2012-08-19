#include "stdafx.h"
#include "GameMenu.h"
#include "Game.h"

GameMenu::GameMenu()
{}

int GameMenu::Start() //return 0 GameExit, 1 GameOn, 2 SplashScreen
{
	const float XPosition = 100.f;
	const float YPosition = 50.f;

	sf::Image imageBack(280, 380, sf::Color(0, 0, 255, 150));
	sf::Sprite spriteBack(imageBack);
	spriteBack.SetCenter(0.f, 0.f);
	spriteBack.SetPosition(XPosition, YPosition);

	MenuButton *menuButton = new MenuButton(XPosition + 50.f, YPosition + 15.f, "Options");
	m_menuButtons.push_back(menuButton);

	Game::GetMainWindow().Draw(spriteBack);

	for (std::vector<MenuButton*>::const_iterator itr = m_menuButtons.begin(); itr != m_menuButtons.end(); ++itr)
	{
		(*itr)->Draw(Game::GetMainWindow());
	}

	Game::GetMainWindow().Display();
	while (1)
	{
		sf::Event Event;
		while (Game::GetMainWindow().GetEvent(Event))
		{
			if (Event.Type == sf::Event::Closed)
			{
				return 0;
			}
			else if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape)
			{
				return 1;
			}
		}
	}

	return true;
}