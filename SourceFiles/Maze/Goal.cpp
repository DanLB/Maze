#include "stdafx.h"
#include "Game.h"
#include "Goal.h"
#include "ServiceLocator.h"

//Call BaseObject constructor
Goal::Goal(float newX, float newY): BaseObject(newX, newY, true, false, "Sprites/Goal.png", dlb::GOAL)
{}

//Check if has collided with Player, if so, change GameState
int Goal::Update()
{
	//If collision occured
	if (CollideWithPlayer())
	{
		//Play Sound
		ServiceLocator::GetAudio()->PlaySound("Sounds/goal.wav");

		//If room is the last one, set GameState to Won, Add 100 points to score
		if (Game::GetCurrentRoom() == dlb::End - 1)
		{
			Game::SetScore(true, 100);
			Game::SetGameState(dlb::Won);
		}
		else
		{
			//Not last room, set GameState to RoomWon so can continue to next room. Add 40 points to score.
			Game::SetGameState(dlb::RoomWon);
			Game::SetScore(true, 40);
		}
	}

	return 1;
}

//Check for collision with player
bool Goal::CollideWithPlayer()
 {
	 //iterator to GameobjectManager collidable objects
	std::vector<BaseObject*>::const_iterator iterator = Game::GetGameObjectManager().GetCollidables().begin();
	
	for (; iterator != Game::GetGameObjectManager().GetCollidables().end(); ++iterator)
	{
		//If object type is Player and collision happened
		if ( ((*iterator)->GetType() == dlb::PLAYER) &&
			(abs( m_position.x - (*iterator)->GetPositionX()) < 32) &&
			(abs( m_position.y - (*iterator)->GetPositionY()) < 32) )
		{
			//Collision occurred
			return true;
		}
	}
	//No collision
	return false;
}