#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "MenuButton.h"

class GameMenu
{
public:
	GameMenu();

	//return 0 GameExit, 1 GameOn, 2 SplashScreen
	int Start();

private:
	std::vector<MenuButton*> m_menuButtons;

};

#endif