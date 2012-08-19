#ifndef BACKGROUND_H
#define BACKGROUND_H

//Class to create a 2D tiled background
class Background
{
private:
	//Vector of sf::Sprite objects used in tiled backgrounds
	std::vector<sf::Sprite*> m_spriteTileList;

	//Number of row (height) and column (width) tiles
	int m_heightCount;
	int m_widthCount;

	//sf::Image containing the background image
	sf::Image m_image;

public:
	Background();
	~Background();

	//reset background
	void ClearBackground();

	//Initialize Background
	void Init(std::string filename);

	//Draw Background
	void Draw(sf::RenderWindow& window);
};

#endif