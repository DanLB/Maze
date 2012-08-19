#include "stdafx.h"
#include "WallHorizontal.h"

//Standard Constructor, WALL type so considered wall for collisions
WallHorizontal::WallHorizontal(float newX, float newY): BaseObject(newX, newY, true, true, "Sprites/WallHorizontal.png", dlb::WALL)
{}

WallHorizontal::~WallHorizontal()
{}

int WallHorizontal::Update()
{
	return 1;
}