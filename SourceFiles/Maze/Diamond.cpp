#include "stdafx.h"
#include "Game.h"
#include "Diamond.h"
#include "ServiceLocator.h"

//Implement the BaseObject Constructor
Diamond::Diamond(float newX, float newY):
BaseObject(newX, newY, true, true, "Sprites/Diamond.png", dlb::DIAMOND)
{
	//One more instance of diamond
	++m_instanceCount;
}

Diamond::~Diamond()
{
	//If game is playing and destructor isn't being called because the game is exiting
	if (Game::GetGameState() != dlb::Exiting && Game::GetGameState() != dlb::Restarting && Game::GetGameState() != dlb::RoomWon && Game::GetGameState() != dlb::Won)
	{
		// Play sound using ServiceLocator
		ServiceLocator::GetAudio()->PlaySound("Sounds/diamond.wav");
		
		//Set Score to 5 relative
		Game::SetScore(true, 5);
	}
	//One less instance regardless of whether the game is being played or not
	//Must be decremented so that initialization of the next room can be successful
	--m_instanceCount;
}

int Diamond::Update()
{
	//Check if collision occured, if it did, return 2 to destroy diamond
	if (CollideWithPlayer())
		return 2;
	
	//No collision; tell GameObjectManager to do nothing
	return 1;
}

//Check if Player collided with Diamond
bool Diamond::CollideWithPlayer()
{
	//Get vector of Collidable objects from GameObjectManager
	for (std::vector<BaseObject*>::const_iterator iterator = Game::GetGameObjectManager().GetCollidables().begin();
		iterator != Game::GetGameObjectManager().GetCollidables().end(); ++iterator)
	{
		//Check if Type is PLAYER and if it has collided
		if ( ((*iterator)->GetType() == dlb::PLAYER) &&
			(abs( m_position.x - (*iterator)->GetPositionX()) < 32) &&
			(abs( m_position.y - (*iterator)->GetPositionY()) < 32) )
		{
			//Collision occurred
			return true;
		}
	}
	//No Collision
	return false;
}

//Return number of instances of Diamond Objects
int const Diamond::GetInstanceCount()
{
	return m_instanceCount;
}

//static variable containing number of instances
int Diamond::m_instanceCount = 0;