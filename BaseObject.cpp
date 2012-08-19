#include "stdafx.h"
#include "BaseObject.h"
#include "Game.h"

//static variable to keep track of next id number
int BaseObject::m_sNextId = 0;

//Constructor to be called by derived classes
BaseObject::BaseObject(float newX, float newY, bool isVisible, bool isSolid, std::string filename, dlb::ObjectType type): m_isVisible(isVisible),
	m_isSolid(isSolid),
	m_id(m_sNextId),
	m_objectType(type)
{
	m_position.x = newX;
	m_position.y = newY;

	//increment static id number so next object has valid, correct id
	++m_sNextId;

	// Attempt to Load Image
	if (!m_Image.LoadFromFile(filename))
	{
		//If it doesn't load
		m_isLoaded = false;
		Game::Error("Image Load " + filename + " failed.");		
	}
	else //loaded
	{
		m_Sprite.SetImage(m_Image);
		m_Sprite.SetCenter(0.0f, 0.0f);
		m_isLoaded = true;
	}

	m_Sprite.SetPosition(newX, newY);
}

BaseObject::~BaseObject()
{}

//If loaded successfully and is visible, Draw the sf::Sprite
void BaseObject::Draw(sf::RenderWindow& window)
{
	if (m_isLoaded && m_isVisible == true)
		window.Draw(m_Sprite);
}