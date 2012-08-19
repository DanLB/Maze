#ifndef MENUBUTTON_H
#define MENUBUTTON_H

class MenuButton
{
public:
	MenuButton(float newX, float newY, std::string newText);

	bool isClicked(sf::Vector2i mouseCoord);

	void Draw(sf::RenderWindow& window) const;

private:
	float m_x;
	float m_y;
	std::string m_text;

	sf::String m_textSprite;
	sf::IntRect m_boundingRect;
	sf::Image m_back;
	sf::Sprite m_sprite;
};

#endif