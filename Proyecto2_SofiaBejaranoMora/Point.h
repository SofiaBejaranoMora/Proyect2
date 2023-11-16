#pragma once
#include<iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	int positionX;
	int positionY;
public:
	Point();
	Point(int positionX, int positionY);
	int getPositionX();
	int getPositionY();
	bool checkTouch(int x,int y);
	void toString();
};

