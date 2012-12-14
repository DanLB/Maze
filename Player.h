#ifndef PLAYER_H
#define PLAYER_H

#include "MovingEntity.h"

class Player : public MovingEntity
{
private:
	//speed
	const float speed;

	//Check to see if collided with walls
	void CollisionWithWalls();
	//Possibly optimize at a later time to check collisions using sprites. Possibly also use a global function, either in Game or more likely in GameObjectManager

public:
	//Implement BaseObject pure virtual functions
	Player(float newX, float newY);

	int Update();
};

#endif