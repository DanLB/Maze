#ifndef WALL_H
#define WALL_H

#include "BaseObject.h"

class Wall : public BaseObject
{
public:
	//Standard functions
	Wall(float newX, float newY);

	int Update();
};

#endif