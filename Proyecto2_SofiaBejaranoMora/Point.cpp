#include "Point.h"

Point::Point(int positionX, int positionY)
{
    this->positionX = positionX;
    this->positionY = positionY;
}

int Point::getPositionX()
{
    return positionX;
}

int Point::getPositionY()
{
    return positionY;
}
