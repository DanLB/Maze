#ifndef FILEINPUT_H
#define FILEINPUT_H

#include "Info.h"

/************************************
**         FileInput Class         **
**                                 **
**      Load Room information      **
**         from .txt file          **
**                                 **
************************************/

class FileInput
{
private:
	//File object to be read from
	static std::ifstream File;	
	
public:
	//Constructor and Destructor
	FileInput();
	~FileInput();

	//Read info from file and return the info in an Info Object
	const static Info& GetInfo();

	//Initialize FileInput with correct Room
	bool SetRoom(int roomNumber);

	//Close the file and prepare for possible next load
	void Close();

	//Info object containing room information
	static Info m_info;
};

#endif