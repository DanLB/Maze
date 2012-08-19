#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "stdafx.h"
#include "Background.h"
#include "Game.h"

Background::Background()
{}

Background::~Background()
{
	if (m_spriteTileList.empty())
	{
		//Free memory in m_spriteTileList
		for (std::vector<sf::Sprite*>::iterator itr = m_spriteTileList.begin(); itr != m_spriteTileList.end(); ++itr)
		{
			delete *itr;
		}
	}
}

//Free memory and clear m_spriteTileList so that a new background can be loaded
void Background::ClearBackground()
{
	for (std::vector<sf::Sprite*>::iterator itr = m_spriteTileList.begin(); itr != m_spriteTileList.end(); ++itr)
	{
		delete *itr;
	}
	m_spriteTileList.clear();
}

//Initialize the Background Image
void Background::Init(std::string filename)
{
	m_image.LoadFromFile("Backgrounds/" + filename);
	m_image.SetSmooth(false);

	//Number of rows and columns
	m_heightCount = Game::GetMainWindowHeight() / m_image.GetHeight();
	m_widthCount = Game::GetMainWindowWidth() / m_image.GetWidth();

	//Create a new sprite for each tile and add it to m_spriteTileList
	sf::Sprite *sprite;
	for (int i = 0; i < m_widthCount; ++i)
	{
		for (int j = 0; j < m_heightCount; ++j)
		{
			sprite = new sf::Sprite(m_image, sf::Vector2f(i * static_cast<float>(m_image.GetWidth()), j * static_cast<float>(m_image.GetHeight())));
			m_spriteTileList.push_back(sprite);
		}
	}
}

//Draw Background
void Background::Draw(sf::RenderWindow& window)
{
	for (std::vector<sf::Sprite*>::const_iterator itr = m_spriteTileList.begin(); itr != m_spriteTileList.end(); ++itr)
	{
		window.Draw((*(*itr)));
	}
}