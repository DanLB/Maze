//Incomplete

#include "stdafx.h"
#include "Button.h"
#include "ServiceLocator.h"

//Call Default Constructor
Button::Button(std::string filename, sf::Vector2f location):
IGui(ServiceLocator::GetImgCache()->GetImage(filename), location)
{
   
}

void Button::Draw(sf::RenderWindow& window)
{
    window.Draw(sprite);
}