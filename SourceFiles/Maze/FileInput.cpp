#include "stdafx.h"
#include "FileInput.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Game.h"


FileInput::FileInput()
{}

FileInput::~FileInput()
{}

//
const Info& FileInput::GetInfo()
{
	//If file is for some reason not open
	if (!File)
	{
		Game::Error("File not open");
		return m_info;
	}

	//temporary variables to hold input from file
	std::string object;
	float x, y;

	//Load background name
	File >> m_info.backgroundFilename;

#ifdef DEBUG
	std::cout << m_info.backgroundFilename << std::endl;
#endif

	//while file is not finished
	while (!File.eof())
	{
		//Enter info into temp variables
		File >> object;
		File >> x;
		File >> y;

#ifdef DEBUG
		std::cout << object << std::endl;
		std::cout << x << std::endl << y << std::endl;
#endif

		//Add information to info object
		m_info.m_object.push_back(object);
		m_info.m_x.push_back(x);
		m_info.m_y.push_back(y);
	}

	return m_info;
}

//Initialize the File with correct room
bool FileInput::SetRoom(int roomNumber)
{
	//change roomNumber to string
	std::stringstream ss;
	ss << roomNumber;

	std::string m_room = "room" + ss.str();

	//Open correct Room file
	File.open("RoomSetup/" + m_room + ".txt");

	//Ensure that it opened
	if (!File)
	{
		Game::Error("File could not be opened");
	}

	return true;
}

//Close file and prepare info object to be reused
void FileInput::Close()
{
	File.close();
	m_info.m_object.clear();
	m_info.m_x.clear();
	m_info.m_y.clear();
}

//Info object returned in GetInfo()
Info FileInput::m_info;

//File to be read --> Opened in SetRoom()
std::ifstream FileInput::File;