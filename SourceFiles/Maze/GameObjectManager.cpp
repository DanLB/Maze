#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h" //For debugging Only!!

GameObjectManager::GameObjectManager()
{}

//Free Memory
GameObjectManager::~GameObjectManager()
{
	for (std::map<int, BaseObject*>::iterator itr = m_mGameObjects.begin(); itr != m_mGameObjects.end(); ++itr)
	{
		delete itr->second;
	}
}

//Add new objects
void GameObjectManager::Add(int key, BaseObject* object)
{
	m_mGameObjects.insert(std::pair<int, BaseObject*>(key, object));

	//If wall object that may need to be collided with
	if (object->GetType() == dlb::WALL)
		m_vWall.push_back(object);

	//If non wall collidable objects (essentially anything that is solid)
	if (object->GetType() != dlb::WALL && object->IsSolid() == true)
		m_vCollidable.push_back(object);
}

//Remove object based on integer key
void GameObjectManager::Remove(int key)
{
	std::map<int, BaseObject*>::const_iterator result = m_mGameObjects.find(key);
	if (result != m_mGameObjects.end())
	{
		delete result->second;
		m_mGameObjects.erase(key);
	}
}

//Return an ptr to object specified by integer key
BaseObject* GameObjectManager::Get(int key)
{
	std::map<int, BaseObject*>::const_iterator result = m_mGameObjects.find(key);
	if (result == m_mGameObjects.end())
		return nullptr;

	return result->second;
}

//Reset so that can go to next level, start over, etc.
void GameObjectManager::ClearObjectManager()
{
	for (std::map<int, BaseObject*>::iterator itr = m_mGameObjects.begin(); itr != m_mGameObjects.end(); ++itr)
	{
		delete itr->second;
	}
	m_mGameObjects.clear();
	m_vWall.clear();
	m_vCollidable.clear();
}

//Return number of objects
int GameObjectManager::GetObjectCount() const
{
	return m_mGameObjects.size();
}

//Update all objects
void GameObjectManager::UpdateAll()
{
	//vector of objects that should be deleted based on their logic
	std::vector<int> toDelete;

	//Update all
	std::map<int, BaseObject*>::iterator itr = m_mGameObjects.begin();
	while (itr != m_mGameObjects.end())
	{
		//2 is return value for object that should be deleted
		if (itr->second->Update() == 2)
			toDelete.push_back(itr->second->GetId());
		++itr;
	}

	//Delete objects that need to be deleted
	for (std::vector<int>::iterator itr = toDelete.begin(); itr != toDelete.end(); ++itr)
	{
		Remove(*itr);
	}
}

//Draw All Objects
void GameObjectManager::DrawAll(sf::RenderWindow& window)
{
	std::map<int, BaseObject*>::iterator itr = m_mGameObjects.begin();
	while (itr != m_mGameObjects.end())
	{
		itr->second->Draw(window);
		++itr;
	}
}