#include "stdafx.h"
#include "SplashScreen.h"
#include "Game.h"
#include "FileInput.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"
#include "HighScore.h"
#include "GameMenu.h"

//Unused Default Constructor
Game::Game()
{}

//Initialized Game, Checks to see if GameLoop should be entered, and if so, calls GameLoop()
void Game::Start()
{
	//If the Game is not unitialized, there is already a Game::Start() called
	if (m_GameState != dlb::Uninitialized)
	{
		return;
	}

	//Initializes m_MainWindow with the const variables initialized in Game.h
	m_MainWindow.Create(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT, BITSPERPIXEL), "Maze Game");
	m_MainWindow.SetFramerateLimit(30); //Cap FPS to 30

	//Create and Register SFMLSoundProvider with a Service Locator
	SFMLSoundProvider soundProvider;
	//Use Service Locator to Play a Sound or Song anywhere in code
	ServiceLocator::RegisterServiceLocator(&soundProvider);

	//Begin playing background music
	ServiceLocator::GetAudio()->PlaySong("Sounds/background.ogg", true);

	ShowSplashScreen(); //show splashscreen

	if (IsExiting() == true)
		return;

	//Load the font for score
	if (!m_scoreFont.LoadFromFile("Fonts/AntsyPants.ttf"))
	{
		Error("Couldn't load m_scoreFont at START");
	}

	//Set Score and the sf::String variable for the score
	m_scoreInt = 0;
	m_scoreText.SetFont(m_scoreFont);
	m_scoreText.SetCenter(0.f, 0.f);
	m_scoreText.SetPosition(32.f, 448.f);
	m_scoreText.SetColor(sf::Color(255, 0, 0));
	m_scoreText.SetSize(22.f);


	do //Place to go back to if Restarting and not Exiting
	{
		InitializeRoom(); //Setup and Load objects for Current Room
	
		while (!IsExiting() && !IsRestarting())
		{
#ifdef DEBUG
			std::cout << 1.f / m_MainWindow.GetFrameTime() << std::endl;
#endif
			GameLoop(); //main Game Loop. Enter if neither restarting nor exiting
		}

		if (IsRestarting()) //If Restarting, Clear everything and prepare for new game
		{
			m_MainWindow.Clear(sf::Color(255, 0, 0));
			m_MainWindow.Display();
			m_GameObjectManager.ClearObjectManager();
			m_background.ClearBackground();
			m_currentRoom = dlb::room1;
			m_scoreInt = 0;
		}
	}while (IsRestarting() && !IsExiting());

	m_MainWindow.Close(); //Close Window
}

//Create a new object and add to GameObjectManager for each entry in the Info object
bool Game::Calculate(Info& info)
{
	//objectIterator, xIterator, yIterator are members in Game.h
	if (*objectIterator == "Wall")
	{
		Wall* wall = new Wall(*xIterator, *yIterator);
		m_GameObjectManager.Add(wall->GetId(), wall);
	}
	else if (*objectIterator == "Player")
	{
		Player* player = new Player(*xIterator, *yIterator);
		m_GameObjectManager.Add(player->GetId(), player);
	}
	else if (*objectIterator == "Goal")
	{
		Goal* goal = new Goal(*xIterator, *yIterator);
		m_GameObjectManager.Add(goal->GetId(), goal);
	}
	else if (*objectIterator == "Diamond")
	{
		Diamond* diamond = new Diamond(*xIterator, *yIterator);
		m_GameObjectManager.Add(diamond->GetId(), diamond);
	}
	else if (*objectIterator == "Door")
	{
		Door* door = new Door(*xIterator, *yIterator);
		m_GameObjectManager.Add(door->GetId(), door);
	}
	else if (*objectIterator == "WallHorizontal")
	{
		WallHorizontal* wallHorizontal = new WallHorizontal(*xIterator, *yIterator);
		m_GameObjectManager.Add(wallHorizontal->GetId(), wallHorizontal);
	}
	else if (*objectIterator == "WallVertical")
	{
		WallVertical* wallVertical = new WallVertical(*xIterator, *yIterator);
		m_GameObjectManager.Add(wallVertical->GetId(), wallVertical);
	}
	else
	{
		Error("Calculate() could not find " + *objectIterator + ". Continue?");
		return false;
	}

	//Set next object in Info
	++objectIterator;
	++xIterator;
	++yIterator;
	
	return true;
}

//MainGameLoop
void Game::GameLoop()
{
	sf::Event currentEvent;
	m_MainWindow.GetEvent(currentEvent);

	switch (m_GameState) //Case for each GameState
	{
		case dlb::Playing:
			//m_MainWindow.Clear(sf::Color(192, 192, 192, 255));
			m_background.Draw(m_MainWindow); //Draw Background

			m_GameObjectManager.UpdateAll(); //Update each object's Logic
			m_GameObjectManager.DrawAll(m_MainWindow); //Draw each object

			SetScoreText(); //Set sf::String for score to current score
			m_MainWindow.Draw(m_scoreText);//Draw Score

			m_MainWindow.Display(); //Display Window

			//If Window Closed, Ensure destructors are called (possibly superfluous) and set m_GameState to Exiting
			if(currentEvent.Type == sf::Event::Closed)
			{
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();
				m_GameState = dlb::Exiting;
			}

			//If Escape pressed, Ensure destructors are called (possibly superfluous) and set m_GameState to Exiting
			if(currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Escape)
			{
				ShowGameMenu();
			}

			//If 'p' pressed, pause game for 15 seconds
			if(currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::P)
			{
				//TODO Make pausable and unpausable
				sf::Sleep(55.f);
			}

			//If 'g' pressed, Set State to Restarting - Restart Game
			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::G)
				m_GameState = dlb::Restarting;

			//If 'r' pressed, Restart Room
			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::R)
			{
				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();

				//Score stays the same!
				m_scoreInt -= 25;
			}

#ifdef DEBUG //In Debug Mode, Numpad will allow to go to different rooms.

			//MAKE SURE YOU KNOW WHAT YOU ARE DOING, THERE IS NO SAFEGAURD TO ENSURE THAT THE ROOM EXISTS
			
			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad1) 
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(1); //Room One

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad2)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(2); //Room Two

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad3)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(3); //Room Three

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad4)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(4); //Room Four

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad5)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(5); //Room Five

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad6)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(6); //Room Six

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad7)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(7); //Room Seven

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad8)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(8); //Room Eight

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad9)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(9); //Room Nine

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}

			if (currentEvent.Type == sf::Event::KeyPressed && currentEvent.Key.Code == sf::Key::Numpad0)
			{
				m_currentRoom = static_cast<dlb::CurrentRoom>(10); //Room Ten

				//Clear everything. Reset to original state
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();

				//Reinitialize everything, set's m_GameState to Playing
				InitializeRoom();
			}
#endif

			break;

		//Room Complete, Rooms to go. Clear and Init() new room
		case dlb::RoomWon:
			{ //need braces so can initialize variables in switch statement

				//Set currentRoom to next room
				int room = m_currentRoom;
				++room;
				m_currentRoom = static_cast<dlb::CurrentRoom>(room);

				//make sure room exists
				if (m_currentRoom == dlb::End)
				{
					m_GameState = dlb::Restarting;
					break;
				}
				
				//Clear
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();
				//Init
				InitializeRoom();
				
				//GameOn!!! ;)
				m_GameState = dlb::Playing;
			}
			break;
			//Code for Restarting done in Game::Start at end of do-loop
		case dlb::Restarting:
			break;
			
		//Game Won
		case dlb::Won:
			//New Window to Display that one has won.
			sf::RenderWindow Win(sf::VideoMode(300, 60, 32), "Win");

			//Messae to Display
			sf::String winMsg("You Win, Press Any Key", sf::Font::GetDefaultFont(), 20.f);
			winMsg.SetPosition(10.f, 20.f);

			Win.Draw(winMsg);
			Win.Display();

			//Loop to process input. If any key is pressed. Close Window
			bool running = true;

			while (running == true)
			{
				sf::Event event;

				while(Win.GetEvent(event))
				{
					if (event.Type == sf::Event::KeyPressed)
					{
						running = false;
						break;
					}
				}
			}
			sf::Sleep(1.f);

			//Display High Score table
			ShowHighScore();
			break;
	}
}

//Return GameObjectManager
GameObjectManager& Game::GetGameObjectManager()
{
	return m_GameObjectManager;
}

//Return MainWindow
sf::RenderWindow& Game::GetMainWindow()
{
	return m_MainWindow;
}

//Return MainWindow Height
int Game::GetMainWindowHeight()
{
	return m_MainWindow.GetHeight();
}

//Return MainWindow Width
int Game::GetMainWindowWidth()
{
	return m_MainWindow.GetWidth();
}

//Returns Current sf::Input - used in Player.cpp to see if key is down
const sf::Input& Game::GetInput()
{
	return m_MainWindow.GetInput();
}

//Returns current status of m_GameState
const dlb::GameState& Game::GetGameState()
{
	return m_GameState;
}

//Returns true if m_GameState == Exiting
bool Game::IsExiting()
{
	if (m_GameState == dlb::Exiting)
		return true;
	else
		return false;
}

//Returns true if m_GameState == Restarting
bool Game::IsRestarting()
{
	if (m_GameState == dlb::Restarting)
		return true;
	else
		return false;
}

//Init current Room
bool Game::InitializeRoom()
{
#ifdef DEBUG
	std::cout << "Initializing Room" << std::endl;
#endif
	bool good;
	FileInput setup; //New FileInput object

	if (setup.SetRoom(m_currentRoom)) //SetCurrent Room
	{//If successful ->
		Info info = setup.GetInfo(); //Create Info object and lood information into it from file

		m_background.Init(info.backgroundFilename); //Initialize background with filename from info

		//Set iterators (defined in Game.h) to Info object vector's beginning
		objectIterator = info.m_object.begin();
		xIterator = info.m_x.begin();
		yIterator = info.m_y.begin();
		
		//Keeps track of what line the information is from
		int count = 1;
	
		//While there is still more information
		while (objectIterator != info.m_object.end())
		{
			good = Calculate(info); //Create new Object and add to GameObjectManager

			if (!good) //If couldn't create new object
			{
				Error("Failed on initialization of: " + dlb::ConvertIntegerToString(count));
				return false; //Couldn't Initialize
			}

			++count;
		}

		setup.Close(); //Close FileInput
		m_GameState = dlb::Playing; //GameOn!
		return true; //Successful
	}
	else //Couldn't Initialize Room
	{
		return false;
	}
}

//Show SplashScreen
void Game::ShowSplashScreen()
{
	SplashScreen splash;
	splash.Show(m_MainWindow);
	if (!IsExiting())
		m_GameState = dlb::Playing;
}

//Set Score. If relative, add score to m_score, else set m_scoreInt to score
void Game::SetScore(bool relative, int score)
{
	if (relative == true)
		m_scoreInt += score;
	else
		m_scoreInt = score;
}

//Return score
int Game::GetScore()
{
	return m_scoreInt;
}

//Set the sf::String m_Score to current Score
void Game::SetScoreText()
{
	m_scoreText.SetText("Score: " + dlb::ConvertIntegerToString(m_scoreInt));
}

//Set m_GameState
void Game::SetGameState(dlb::GameState state)
{
	m_GameState = state;
}

//Returns m_currentRoom
const dlb::CurrentRoom Game::GetCurrentRoom()
{
	return m_currentRoom;
}

//Create HighScore object with m_scoreInt and then Display High Score Table. Set m_GameState to Restarting
void Game::ShowHighScore()
{
	HighScore highscore(m_scoreInt);
	highscore.ShowHighScore();
	m_GameState = dlb::Restarting;
}

//Display Error Message, Escape or Window Close exits; Return or Space restart game
void Game::Error(std::string errorMessage)
{
	m_background.Draw(m_MainWindow);

	sf::String string(errorMessage);
	string.SetPosition(240.f, 160.f);
	string.SetColor(sf::Color::Red);
	m_MainWindow.Draw(string);

	bool waiting = true;
	sf::Event Event;

	while (waiting == true)
	{
		while (m_MainWindow.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed)
			{
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();
				m_GameState = dlb::Exiting;
				waiting = false;
			}

			//If Escape pressed, Ensure destructors are called (possibly superfluous) and set m_GameState to Exiting
			if(Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape)
			{
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();
				m_GameState = dlb::Exiting;
				waiting = false;
			}

			/*if (Event.Type == sf::Event::KeyPressed && (Event.Key.Code == sf::Key::Space || Event.Key.Code == sf::Key::Return))
			{
				GotoRoom(1)
			}*/

			if (Event.Type == sf::Event::KeyPressed)
			{
				m_GameObjectManager.ClearObjectManager();
				m_background.ClearBackground();
				m_GameState = dlb::Exiting;
				waiting = false;
			}
		}
	}
}

//Set the Room to be played
void Game::GotoRoom(int roomCode)
{
	m_currentRoom = static_cast<dlb::CurrentRoom>(roomCode);

	//Clear everything. Reset to original state
	m_GameObjectManager.ClearObjectManager();
	m_background.ClearBackground();

	//Reinitialize everything, set's m_GameState to Playing
	InitializeRoom();
}

void Game::ShowGameMenu()
{
	GameMenu gameMenu;
	int bMenu = gameMenu.Start(); //returns 1 for gameOn, 2 to SplashScreen, 0 to exit and close
	//TODO  check whether gameOn or exit. if exit, free memory and close window
	switch (bMenu)
	{
	case 0: //Exit the Game
		m_GameObjectManager.ClearObjectManager();
		m_background.ClearBackground();
		m_GameState = dlb::Exiting;
		break;
	case 1: //gameOn
		//Do Nothing
		break;
	case 2: //Go to SplashScreen
		break;
	}
}

//static variables
sf::RenderWindow Game::m_MainWindow;
GameObjectManager Game::m_GameObjectManager;
dlb::GameState Game::m_GameState = dlb::Uninitialized;
dlb::CurrentRoom Game::m_currentRoom = dlb::room1;
std::vector<std::string>::const_iterator Game::objectIterator;
std::vector<float>::const_iterator Game::xIterator;
std::vector<float>::const_iterator Game::yIterator;
sf::Font Game::m_scoreFont;
int Game::m_scoreInt;
sf::String Game::m_scoreText;
Background Game::m_background;