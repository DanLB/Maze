#include "stdafx.h"
#include "WallVertical.h"

//Standard Constructor, WALL type so considered wall for collisions
WallVertical::WallVertical(float newX, float newY): BaseObject(newX, newY, true, true, "Sprites/WallVertical.png", dlb::WALL)
{}

WallVertical::~WallVertical()
{}

int WallVertical::Update()
{
	return 1;
}