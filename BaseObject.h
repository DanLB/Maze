#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED

#include <string>
#include "EnumState.h"

class BaseObject
{
private:
	//id number
	int m_id;

	//sf::Image containing the image to be displayed
	sf::Image m_Image;

	//variable for if object is visible, solid, loaded
	bool m_isVisible, m_isSolid, m_isLoaded;
	
	//variable for object's type. Uses enum defined in EnumState.h
	dlb::ObjectType m_objectType;

protected:
	//Object's Position
	sf::Vector2f m_position;
	
	//Object's sf::Sprite object that is manipulated and drawn
	sf::Sprite m_Sprite;

public:
	//static variable keeping track of next valid ID
	static int m_sNextId;

	//Constructor with variables for Position, visible, solid, filename to load image, and its type
	BaseObject(float newX, float newY, bool isVisible, bool isSolid, std::string filename, dlb::ObjectType type);

	//Unused Destructor, may be implemented in derived classes
	virtual ~BaseObject();

	//Update the Object's Logic, Position, etc. To be implemented in the derived object
	virtual int Update() = 0; //In GameObjectManager return 1 -> do nothing. If return 2 -> delete this object
	
	//Draw the Sprite
	virtual void Draw(sf::RenderWindow& window);

	//return Id Number
	int GetId() const {return m_id;}

	//Return if the object is solid
	bool IsSolid() const {return m_isSolid;}

	//Return object's type
	dlb::ObjectType GetType() const {return m_objectType;}

	//return object's Position
	float GetPositionX() const {return m_position.x;}
	float GetPositionY() const {return m_position.y;}
};

#endif