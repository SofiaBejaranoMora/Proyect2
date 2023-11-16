#include "Point.h"

Point::Point()
{
}

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

bool Point::checkTouch(int x, int y)
{
    int distance = sqrt(pow(x - positionX, 2) + pow(y - positionY, 2));
    if (distance <= 10) {
        return true;
    }
    return false;
}

void Point::toString()
{
    cout << "punto X = " << positionX << " punto y = " << positionY << endl;
}
