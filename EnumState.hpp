#ifndef ENUMSTATE_H_INCLUDED
#define ENUMSTATE_H_INCLUDED

namespace dlb
{
	//Enum Type to help keep track of what room the game is on and to help determine what file to load the level from.
	enum CurrentRoom {room1 = 1, room2, room3, End};

	//Enum Type to keep track of the current state of the game.
	enum GameState {Uninitialized, Playing, Exiting, RoomWon, Won, Restarting};

	//Enum Type used in BaseObject to keep track of what type of object something is.
	enum ObjectType {WALL, PLAYER, GOAL, DIAMOND};

	//Function to convert an integer to a std::string. Defined in Maze.cpp
	std::string ConvertIntegerToString(int integer);
};

#endif