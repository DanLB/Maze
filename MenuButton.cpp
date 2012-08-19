#include "stdafx.h"
#include "MenuButton.h"

MenuButton::MenuButton(float newX, float newY, std::string newText): m_x(newX),
	m_y(newY),
	m_text(newText),
	m_boundingRect(newX, newY, newX + 100, newY + 50),
	m_back(180, 50, sf::Color(255, 255, 255, 210)),
	m_sprite(m_back, sf::Vector2f(newX, newY))
{
	m_textSprite.SetCenter(0.f, 0.f);
	m_textSprite.SetPosition(newX + 35.f, newY + 8.f);
	m_textSprite.SetText(m_text);
	m_textSprite.SetColor(sf::Color::Red);
}

bool MenuButton::isClicked(sf::Vector2i mouse)
{
	return m_boundingRect.Contains(mouse.x, mouse.y);
}

void MenuButton::Draw(sf::RenderWindow& window) const
{
	window.Draw(m_sprite);
	window.Draw(m_textSprite);
}