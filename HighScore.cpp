#include "stdafx.h"
#include "HighScore.h"
#include "Game.h"
#include <fstream>
#include <cstdlib>

//Constructor
HighScore::HighScore(int score): m_newscore(score),
	m_isBetter(false)
{
	//Reserves space for the sf::String vectors
	vHighScoreStrings.reserve(10);
	vHighScoresIntStrings.reserve(10);
}

//Releases memory used by sf::String vectors
HighScore::~HighScore()
{
	for ( std::vector<sf::String*>::iterator itr = vHighScoreStrings.begin(); itr != vHighScoreStrings.end(); ++itr)
	{
		delete *itr;
	}

	for ( std::vector<sf::String*>::iterator itr = vHighScoresIntStrings.begin(); itr != vHighScoresIntStrings.end(); ++itr)
	{
		delete *itr;
	}
}

//Displays the highscore
void HighScore::ShowHighScore()
{
	//temp variables to store input from file
	std::vector<std::string> vHighScoreNames;
	std::vector<int> vHighScoreInts;

	std::ifstream high("highscore.txt");

	//Check if high opened
	if (!high)
	{
		//didnt open
		Game::Error("highscore.txt could not be opened.");
		return;
	}
	
	//temporary variables to store file input
	std::string sHighScoreName;
	int iHighScoreInt;

	//bool for whether the new highscore has been found
	bool set = false;

	for (int i = 0; i < 10; ++i)
	{
		
		high >> sHighScoreName;
		high >> iHighScoreInt;

		//check whether current highscores are >= new highscore
		if (iHighScoreInt >= m_newscore)
		{
			vHighScoreInts.push_back(iHighScoreInt);
			vHighScoreNames.push_back(sHighScoreName);
		}
		else if (set == false)
		{
			//insert new highscore and string holder
			vHighScoreInts.push_back(m_newscore);
			vHighScoreNames.push_back(" ");
			set = true;
			m_isBetter = true;
			//pushback inputs from file
			vHighScoreInts.push_back(iHighScoreInt);
			vHighScoreNames.push_back(sHighScoreName);
			//To ensure only 10 and not 11 values are entered into vectors
			i++;
		}
		else
		{
			vHighScoreInts.push_back(iHighScoreInt);
			vHighScoreNames.push_back(sHighScoreName);
		}
	}

	high.close();

	//counter to help keep track of where the text should be displayed
	int pos = 0;

	//Create sf::Strings for int scores and pushback vector IntStrings
	for (std::vector<int>::iterator itrScore = vHighScoreInts.begin(); itrScore != vHighScoreInts.end(); ++itrScore, ++pos)
	{
		sf::String *string = new sf::String(dlb::ConvertIntegerToString(*itrScore), sf::Font::GetDefaultFont(), 20.f);

		string->SetPosition(250.f, pos * 30.f + 10.f);
		string->SetColor(sf::Color::Black);
		vHighScoresIntStrings.push_back(string);
	}

	pos = 0;

	//Create sf::Strings for score names and pushback vector ScoreNames
	for (std::vector<std::string>::iterator itrName = vHighScoreNames.begin();
		itrName != vHighScoreNames.end(); ++itrName, ++pos)
	{
		sf::String *string = new sf::String(*itrName, sf::Font::GetDefaultFont(), 20.f);

		string->SetPosition(10.f, pos * 30.f + 10.f);
		string->SetColor(sf::Color::Black);
		vHighScoreStrings.push_back(string);
	}	

	sf::RenderWindow App(sf::VideoMode(300, 350, 32), "High Scores");

	bool bShowHighScores = true;
	sf::Event event;

	//Iterator to check for new ScoreNameString
	std::vector<sf::String*>::iterator itr;

	//string for entering new name --> '_' is so the user knows which name he/she is modifying
	std::string newString = "_";

	//There was a new highscore
	if (m_isBetter)
	{
		for (itr = vHighScoreStrings.begin(); itr != vHighScoreStrings.end(); ++itr)
		{
			if ( static_cast<std::string>((*itr)->GetText()) == " ")
			{
				(*itr)->SetText(newString);
				break;
			}
		}
	}
	else //No new highscore. Display scores and then exit when user closes window or hits 'return' or 'escape'
	{
		App.Clear(sf::Color::White);

		for (std::vector<sf::String*>::iterator itrInt = vHighScoresIntStrings.begin(); itrInt != vHighScoresIntStrings.end(); ++itrInt)
		{
				App.Draw(*(*itrInt));
		}

		for (std::vector<sf::String*>::iterator itrName = vHighScoreStrings.begin(); itrName != vHighScoreStrings.end(); ++itrName)
		{
			App.Draw(*(*itrName));
		}

		App.Display();

		while (bShowHighScores)
		{
			while (App.GetEvent(event))
			{
				if (event.Type == sf::Event::Closed)
				{
					App.Close();
					bShowHighScores = false;
				}

				if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Return)
				{
					App.Close();
					bShowHighScores = false;
				}

				if  (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
				{
					App.Close();
					bShowHighScores = false;
				}
			}
		}

		return;
	}

	//New highscore. Get name for new highscore
	while (bShowHighScores)
	{
		while (App.GetEvent(event))
		{
			if (event.Type == sf::Event::Closed)
			{
				App.Close();
				bShowHighScores = false;
			}

			if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Return)
			{
				App.Close();
				bShowHighScores = false;
			}

			if  (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
				{
				App.Close();
				bShowHighScores = false;
			}

			//Remove trailing '_'
			if (event.Type == sf::Event::KeyPressed && !newString.empty() && *newString.rbegin() == '_')
			{
				if (newString.size() > 0)
				newString.resize(newString.length() - 1);
			}

			//Backspace
			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Back))
			{
				if (newString.size() > 0)
					newString.resize(newString.length() - 1);
			}

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::A))
				if (event.Key.Shift == true)
					newString += "A";
				else
					newString += "a";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::B))
				if (event.Key.Shift == true)
					newString += "B";
				else
					newString += "b";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::C))
				if (event.Key.Shift == true)
					newString += "C";
				else
					newString += "c";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::D))
				if (event.Key.Shift == true)
					newString += "D";
				else
					newString += "d";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::E))
				if (event.Key.Shift == true)
					newString += "E";
				else
				newString += "e";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::F))
				if (event.Key.Shift == true)
					newString += "F";
				else
				newString += "f";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::G))
				if (event.Key.Shift == true)
					newString += "G";
				else
				newString += "g";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::H))
				if (event.Key.Shift == true)
					newString += "H";
				else
				newString += "h";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::I))
				if (event.Key.Shift == true)
					newString += "I";
				else
				newString += "i";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::J))
				if (event.Key.Shift == true)
					newString += "J";
				else
				newString += "j";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::K))
				if (event.Key.Shift == true)
					newString += "K";
				else
				newString += "k";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::L))
				if (event.Key.Shift == true)
					newString += "L";
				else
				newString += "l";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::M))
				if (event.Key.Shift == true)
					newString += "M";
				else
				newString += "m";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::N))
				if (event.Key.Shift == true)
					newString += "N";
				else
				newString += "n";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::O))
				if (event.Key.Shift == true)
					newString += "O";
				else
				newString += "o";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::P))
				if (event.Key.Shift == true)
					newString += "P";
				else
				newString += "p";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Q))
				if (event.Key.Shift == true)
					newString += "Q";
				else
				newString += "q";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::R))
				if (event.Key.Shift == true)
					newString += "R";
				else
				newString += "r";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::S))
				if (event.Key.Shift == true)
					newString += "S";
				else
				newString += "s";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::T))
				if (event.Key.Shift == true)
					newString += "T";
				else
				newString += "t";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::U))
				if (event.Key.Shift == true)
					newString += "U";
				else
				newString += "u";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::V))
				if (event.Key.Shift == true)
					newString += "V";
				else
				newString += "v";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::W))
				if (event.Key.Shift == true)
					newString += "W";
				else
				newString += "w";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::X))
				if (event.Key.Shift == true)
					newString += "X";
				else
				newString += "x";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Y))
				if (event.Key.Shift == true)
					newString += "Y";
				else
				newString += "y";

			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Z))
				if (event.Key.Shift == true)
					newString += "Z";
				else
				newString += "z";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num0) || (event.Key.Code == sf::Key::Numpad0)))
					newString += "0";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num1) || (event.Key.Code == sf::Key::Numpad1)))
					newString += "1";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num2) || (event.Key.Code == sf::Key::Numpad2)))
					newString += "2";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num3) || (event.Key.Code == sf::Key::Numpad3)))
					newString += "3";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num4) || (event.Key.Code == sf::Key::Numpad4)))
					newString += "4";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num5) || (event.Key.Code == sf::Key::Numpad5)))
					newString += "5";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num6) || (event.Key.Code == sf::Key::Numpad6)))
					newString += "6";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num7) || (event.Key.Code == sf::Key::Numpad7)))
					newString += "7";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num8) || (event.Key.Code == sf::Key::Numpad8)))
					newString += "8";

			if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Num9) || (event.Key.Code == sf::Key::Numpad9)))
					newString += "9";
		}

		//Add trailing '_'
		if (newString.empty() == true)
			newString = "_";
		else if (*newString.rbegin() != '_')
		  newString += "_";

		//Set new text
		(*itr)->SetText(newString);

		App.Clear(sf::Color::White);

		for (std::vector<sf::String*>::iterator itrInt = vHighScoresIntStrings.begin(); itrInt != vHighScoresIntStrings.end(); ++itrInt)
		{
				App.Draw(*(*itrInt));
		}

		for (std::vector<sf::String*>::iterator itrName = vHighScoreStrings.begin(); itrName != vHighScoreStrings.end(); ++itrName)
		{
			App.Draw(*(*itrName));
		}

		App.Display();
	}

	//Remove trailing '_' and if no input entered set name to "Unknown"
	newString = (*itr)->GetText();
	if (newString == "_")
	{
		newString = "Unknown";
	}
	else if (*newString.rbegin() == '_')
	{
		if (newString.size() > 0)
		newString.resize(newString.length() - 1);
	}

	(*itr)->SetText(newString);

	//Open file for saving highscores
	std::ofstream highOutput("highscore.txt");

	if (!high)
	{
		Game::Error("highscore.txt could not be opened.");
	}

	//iterators
	std::vector<sf::String*>::iterator itrName;
	std::vector<sf::String*>::iterator itrInt;

	//save highscores
	for (itrName = vHighScoreStrings.begin(), itrInt = vHighScoresIntStrings.begin(); itrName != vHighScoreStrings.end() &&
		itrInt != vHighScoresIntStrings.end(); ++itrName, ++itrInt)
	{
		highOutput << static_cast<std::string>((*itrName)->GetText()) << " ";
		highOutput << static_cast<std::string>((*itrInt)->GetText()) << std::endl;
	}

	highOutput.close();
}


//419