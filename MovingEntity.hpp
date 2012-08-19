#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "BaseObject.h"

class MovingEntity: public BaseObject
{
protected:
	//speed
	float m_hSpeed, m_vSpeed;

public:
	//Constructor
	MovingEntity(float newX, float newY, bool isVisible, bool isSolid, std::string filename, dlb::ObjectType type);
	
	//Update position by speed
	void UpdatePosition();
};

#endif