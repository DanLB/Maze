#include "stdafx.h"
#include "Game.h"
#include "Player.h"

Player::Player(float newX, float newY): speed (4.f),
	MovingEntity(newX, newY, true, true, "Sprites/Player.png", dlb::PLAYER)
{}

// TODO make update use elapsed time so always move the same speed
int Player::Update()
{
#ifdef DEBUG
	std::cout << Game::GetMainWindow().GetFrameTime() << std::endl;
#endif

	//Check for input and set speed. Make sure always on 32 x 32 grid.
	if (Game::GetInput().IsKeyDown(sf::Key::Down))
	{
		if ( static_cast<int>(m_position.y) % 32 == 0)
			if (m_hSpeed == 0)
				m_vSpeed = speed ;//* Game::GetMainWindow().GetFrameTime();
	}		
	else if (Game::GetInput().IsKeyDown(sf::Key::Up))
	{
		if ( static_cast<int>(m_position.y) % 32 == 0)
			if (m_hSpeed == 0)
				m_vSpeed = -speed ;//* Game::GetMainWindow().GetFrameTime();
	}
	else if ( static_cast<int>(m_position.y) % 32 == 0)
	{
		m_vSpeed = 0;
	}
		
	if (Game::GetInput().IsKeyDown(sf::Key::Left))
	{
		if ( static_cast<int>(m_position.x) % 32 == 0)
			if (m_vSpeed == 0)
				m_hSpeed = -speed ;//* Game::GetMainWindow().GetFrameTime();
	}
	else if (Game::GetInput().IsKeyDown(sf::Key::Right))
	{
		if (static_cast<int>(m_position.x) % 32 == 0)
			if (m_vSpeed == 0)
				m_hSpeed = speed ;//* Game::GetMainWindow().GetFrameTime();
	}
	else if ( static_cast<int>(m_position.x) % 32 == 0)
	{
		m_hSpeed = 0;
	}

	//Stop if no arrow key is down
	if (!(Game::GetInput().IsKeyDown(sf::Key::Right)) &&
		!(Game::GetInput().IsKeyDown(sf::Key::Left)) &&
		!(Game::GetInput().IsKeyDown(sf::Key::Up)) &&
		!(Game::GetInput().IsKeyDown(sf::Key::Down)))
	{
		if ((static_cast<int>(m_position.x) % 32 == 0) &&
			(static_cast<int>(m_position.y) % 32 == 0))
		{
			m_hSpeed = 0;
			m_vSpeed = 0;
		}
	}

	//Check for collisions
	CollisionWithWalls();

	//Update Position
	UpdatePosition();

#ifdef DEBUG
	std::cout << "PlayerX: " << m_position.x << " PlayerY: " << m_position.y <<std::endl;
#endif

	return 1;
}

//Check for collisions going each direction and stopping in grid if true
void Player::CollisionWithWalls()
{
	if (m_hSpeed > 0)
	{
		for (std::vector<BaseObject*>::const_iterator wallIterator = Game::GetGameObjectManager().WallsForCollision().begin();
			wallIterator != Game::GetGameObjectManager().WallsForCollision().end(); ++wallIterator)
		{
			if ( (((*wallIterator)->GetPositionX() - m_position.x) <= 63) &&
				((abs((*wallIterator)->GetPositionY() - m_position.y)) < 32) &&
				(((*wallIterator)->GetPositionX() - m_position.x) >= 0) )
			{
				if ((static_cast<int>(m_position.x) % 32 == 0) &&
				(static_cast<int>(m_position.y) % 32 == 0))
				{
					m_vSpeed = 0;
					m_hSpeed = 0;
				}
			}
		}
	}
	else if (m_hSpeed < 0)
	{
		for (std::vector<BaseObject*>::const_iterator wallIterator = Game::GetGameObjectManager().WallsForCollision().begin();
			wallIterator != Game::GetGameObjectManager().WallsForCollision().end(); ++wallIterator)
		{
			if ( ((m_position.x - (*wallIterator)->GetPositionX()) <= 36) &&
				((abs((*wallIterator)->GetPositionY() - m_position.y)) < 32) &&
				((m_position.x - (*wallIterator)->GetPositionX()) > 0) )
			{
				if ((static_cast<int>(m_position.x) % 32 == 0) &&
				(static_cast<int>(m_position.y) % 32 == 0))
				{
					m_vSpeed = 0;
					m_hSpeed = 0;
				}
			}
		}
	}
	else if (m_vSpeed > 0)
	{
		for (std::vector<BaseObject*>::const_iterator wallIterator = Game::GetGameObjectManager().WallsForCollision().begin();
			wallIterator != Game::GetGameObjectManager().WallsForCollision().end(); ++wallIterator)
		{
			if ( (((*wallIterator)->GetPositionY() - m_position.y) <= 45) &&
				((abs((*wallIterator)->GetPositionX() - m_position.x)) < 32) &&
				(((*wallIterator)->GetPositionY() - m_position.y) >= 0) )
			{
				if ((static_cast<int>(m_position.x) % 32 == 0) &&
				(static_cast<int>(m_position.y) % 32 == 0))
				{
					m_vSpeed = 0;
					m_hSpeed = 0;
				}
			}
		}
	}
	else if (m_vSpeed < 0)
	{
		for (std::vector<BaseObject*>::const_iterator wallIterator = Game::GetGameObjectManager().WallsForCollision().begin();
			wallIterator != Game::GetGameObjectManager().WallsForCollision().end(); ++wallIterator)
		{
			if ( ((m_position.y - (*wallIterator)->GetPositionY()) <= 45) &&
				((abs((*wallIterator)->GetPositionX() - m_position.x)) < 32) &&
				((m_position.y - (*wallIterator)->GetPositionY()) >= 0) )
			{
				if ((static_cast<int>(m_position.x) % 32 == 0) &&
				(static_cast<int>(m_position.y) % 32 == 0))
				{
					m_vSpeed = 0;
					m_hSpeed = 0;
				}
			}
		}
	}
}