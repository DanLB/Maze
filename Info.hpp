#ifndef INFO_H
#define INFO_H

#include <string>

//struct to store the information for each room. Used by FileInput and passed to Game
struct Info
{
	std::string backgroundFilename;

	std::vector<std::string> m_object;
	std::vector<float> m_x;
	std::vector<float> m_y;
};

#endif