#include "stdafx.h"
#include "Wall.h"

Wall::Wall(float newX, float newY): BaseObject(newX, newY, true, true, "Sprites/Wall.png", dlb::WALL)
{}

int Wall::Update()
{
	return 1;
}
