#ifndef GOAL_H
#define GOAL_H

#include "BaseObject.h"

class Goal : public BaseObject
{
public:
	//Constructor
	Goal(float newX, float newY);

	//Implement base class Update()
	int Update();

	//Check if has collided with Player
	bool CollideWithPlayer();
};

#endif