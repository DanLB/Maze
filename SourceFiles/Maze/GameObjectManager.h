#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "BaseObject.h"
#include "Wall.h"

class GameObjectManager
{
private:
	//Map of objects
	std::map<int, BaseObject*> m_mGameObjects;

	//vector of walls and non-wall collidable objects
	std::vector<BaseObject*> m_vWall;
	std::vector<BaseObject*> m_vCollidable;

public:
	GameObjectManager();
	~GameObjectManager();

	//Add new Object
	void Add(int key, BaseObject* object);

	//Remove specified object
	void Remove(int key);

	//Return object
	BaseObject* Get(int key);

	//Reset GameObjectManager
	void ClearObjectManager();

	//Return number of objects in Manager
	int GetObjectCount() const;

	//Update and Draw all objets
	void UpdateAll();
	void DrawAll(sf::RenderWindow& window);

	//Functions for other objects to get walls or collidable objects to check for collisions
	std::vector<BaseObject*>& WallsForCollision() {return m_vWall;}
	std::vector<BaseObject*>& GetCollidables() {return m_vCollidable;}
};

#endif