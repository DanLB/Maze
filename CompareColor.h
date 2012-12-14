#ifndef COMPARECOLOR_H
#define COMPARECOLOR_H

//compare two colors
class CompareColor
{
public:
    bool operator() (const sf::Color& c1, const sf::Color& c2)
    {
        if (c1.r < c2.r)
        {
            return true;
        }
        else if (c1.r > c2.r)
        {
            return false;
        }
        else
        {
            if (c1.g < c2.g)
            {
                return true;
            }
            else if (c1.g > c2.g)
            {
                return false;
            }
            else
            {
                if (c1.b < c2.b)
                {
                    return true;
                }
                else if (c1.b > c2.b)
                {
                    return false;
                }
                else
                {
                    if (c1.r < c2.r)
                    {
                        return true;
                    }
                    else if (c1.r > c2.r)
                    {
                        return false;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
};

#endif