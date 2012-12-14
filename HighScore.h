#ifndef HIGHSCORE_H
#define HIGHSCORE_H

class HighScore
{
private:
	//vector of sf::String pointers for the Names of the highscores
	std::vector<sf::String*> vHighScoreStrings;

	//vector for the integers of the highscores
	std::vector<sf::String*> vHighScoresIntStrings;

	//The score from the current game
	int m_newscore;

	//bool of whether m_newscore should be in the top 10 for scores
	bool m_isBetter;

public:
	HighScore(int score);
	~HighScore();

	//Creates new window, displays high scores, and gets the name for a new high score if necessary
	void ShowHighScore();
};

#endif