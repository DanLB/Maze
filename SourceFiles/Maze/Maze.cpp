// Maze.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "Game.h"

int main()
{
	Game::Start();
	
	return 0;
}

//Function for converting an integer to a std::string
std::string dlb::ConvertIntegerToString(int integer)
{
	std::stringstream ss;
	ss << integer;
	std::string string = ss.str();

	return string;
}