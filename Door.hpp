#ifndef DOOR_H
#define DOOR_H

class Door : public BaseObject
{
public:
	//Constructor and Destructor
	Door(float newX, float newY);
	~Door();

	//Implement Base class's Update()
	int Update();
};

#endif