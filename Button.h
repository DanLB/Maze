//Incomplete

#ifndef BUTTON_H
#define BUTTON_H

#include "IGui.h"

class Button : public IGui
{
public:
    Button(std::string filename, sf::Vector2f location);
    Button(sf::Color color, sf::Vector2f location);
    void virtual Draw(sf::RenderWindow& window);
    void ChangeText(std::string newstring);
    void ChangeFont(sf::Font font);

private:
    std::string text;
    sf::String sText;
    sf::Font font;
};

#endif