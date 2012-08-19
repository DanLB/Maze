#ifndef WALLVERTICAL_H
#define WALLVERTICAL_H

class WallVertical : public BaseObject
{
public:
	//Standard Functions for BaseObject
	WallVertical(float newX, float newY);
	~WallVertical();

	int Update();
};

#endif