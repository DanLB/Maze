#include "stdafx.h"
#include "MovingEntity.h"

//Constructor. Calls BaseObject Constructor and sets speed to 0
MovingEntity::MovingEntity(float newX, float newY, bool isVisible, bool isSolid, std::string filename, dlb::ObjectType type):
	m_hSpeed(0.0f),
	m_vSpeed(0.0f),
	BaseObject(newX, newY, isSolid, isVisible, filename, type)
{}

//Call in derived classes' Update(). Should be the last or nearly so class called.
//Updates Position by the object's speed
void MovingEntity::UpdatePosition()
{
	m_position.x += m_hSpeed;
	m_position.y += m_vSpeed;

	m_Sprite.SetPosition(m_position.x, m_position.y);
}