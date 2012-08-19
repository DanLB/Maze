#ifndef WALLHORIZONTAL_H
#define WALLHORIZONTAL_H

class WallHorizontal : public BaseObject
{
public:
	//Standard functions for BaseObject derived class
	WallHorizontal(float newX, float newY);
	~WallHorizontal();

	int Update();
};

#endif