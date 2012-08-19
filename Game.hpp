#ifndef GAME_H
#define GAME_H

#include "SFML/Window.hpp"
#include "EnumState.h" //GameStates, Rooms defined here.
#include "Background.h"
#include "Player.h"
#include "Goal.h"
#include "Wall.h"
#include "Diamond.h"
#include "Door.h"
#include "WallVertical.h"
#include "WallHorizontal.h"
#include "GameObjectManager.h"
#include "Info.h"

class Game
{
private:
	static sf::RenderWindow m_MainWindow; //Window to Draw To
	static GameObjectManager m_GameObjectManager; //Manages Game Objects

	const static int Game::SCREENHEIGHT = 480;
	const static int Game::SCREENWIDTH = 480;
	const static int Game::BITSPERPIXEL = 32;

	static dlb::CurrentRoom m_currentRoom; //Room currently being played

	//Adds Objects to GameObjectManager based on the info object
	//Called in InitializeRoom()
	static bool Calculate(Info& info);

	//Info object iterators. Used in InitializeRoom() and Calculate()
	static std::vector<std::string>::const_iterator objectIterator;
	static std::vector<float>::const_iterator xIterator;
	static std::vector<float>::const_iterator yIterator;

	static int m_scoreInt; //Value of score as int
	static sf::Font m_scoreFont;//Font used to draw score to screen
	static sf::String m_scoreText; //Value of score as string

	//Used to set the score string to the score int.
	//Called each game loop
	static void SetScoreText();

	//Initialize the current level
	static bool InitializeRoom();
	//Creates and Displays the SplashScreen
	static void ShowSplashScreen();

	//Background object that draws the background
	//First thing drawn every game loop
	static Background m_background;

public:
	//Current gamestate
	static dlb::GameState m_GameState;

	//Unused Constructor
	Game();

	//Initializes basic variables and calls and determines if GameLoop() should be called
	static void Start();
	//Main Game Loop
	static void GameLoop();

	//Returns GameObjectManager
	static GameObjectManager& GetGameObjectManager();
	//Returns Window
	static sf::RenderWindow& GetMainWindow();
	//Returns window height
	static int GetMainWindowHeight();
	//Returns Window width
	static int GetMainWindowWidth();
	//Returns the current input
	//Used in Player object to determine what key is down
	static const sf::Input& GetInput();
	//Returns Gamestate
	static const dlb::GameState& GetGameState();
	//Returns if m_GameState == Exiting
	static bool IsExiting();
	//Returns if m_GameState == Restarting
	static bool IsRestarting();
	//Returns the current Room
	static const dlb::CurrentRoom GetCurrentRoom();

	//Setter Function for the m_GameState
	static void SetGameState(dlb::GameState state);

	//Setter Function for the score
	static void SetScore(bool relative, int score);
	//Returns Score
	static int GetScore();

	//Displays the HighScore Screen
	static void ShowHighScore();

	//function to display error message
	static void Error(std::string errorMessage);

	static void GotoRoom(int roomCode);

	static void ShowGameMenu();
};

#endif