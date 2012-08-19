#include "stdafx.h"
#include "Game.h"
#include "Door.h"
#include "Diamond.h"
#include "ServiceLocator.h"

//Implement Base class's Constructor
Door::Door(float newX, float newY): BaseObject(newX, newY, true, true, "Sprites/Door.png", dlb::WALL)
{}

Door::~Door()
{
	//If in Game
	if (Game::GetGameState() != dlb::Exiting && Game::GetGameState() != dlb::Restarting && Game::GetGameState() != dlb::RoomWon && Game::GetGameState() != dlb::Won)
	{
		ServiceLocator::GetAudio()->PlaySound("Sounds/door.wav");
	}
}

int Door::Update()
{
	//Check number of diamond instances
	//--If there are no more diamonds, return 2 so GameObjectManager knows to delete door
	if (Diamond::GetInstanceCount() == 0)
		return 2;
	else
		return 1;
}