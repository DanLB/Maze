//Incomplete

#ifndef IGUI_H
#define IGUI_H

//Add function to change location
class IGui
{
public:
    IGui(sf::Image* img, sf::Vector2f loc);
    virtual ~IGui();

    void ChangeImage(sf::Image* newImage);
    void virtual Draw(sf::RenderWindow& window) = 0;
    bool IsClicked(sf::Vector2f mouse);
    int GetId();

protected:
    sf::Image* image;
    sf::Rect<int> boundingBox;
    sf::Sprite sprite;

private:
    static int s_id;
    int id;    
    sf::Vector2f location;
};

#endif