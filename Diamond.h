#ifndef DIAMOND_H
#define DIAMOND_H

#include "BaseObject.h"

class Diamond : public BaseObject
{
private:
	//Number of instances; to be used by door objects
	static int m_instanceCount;

public:
	//Constructor and Destructor
	Diamond(float newX, float newY);
	~Diamond();

	//BaseObject Update() implementation
	int Update();

	//check if collided with player; called in Update()
	bool CollideWithPlayer();

	//Return m_instanceCount
	static int const GetInstanceCount();
};

#endif