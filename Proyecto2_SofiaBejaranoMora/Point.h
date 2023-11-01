#pragma once
#include<iostream>

using namespace std;

class Point
{
private:
	int positionX;
	int positionY;
public:
	Point(int positionX, int positionY);
	int getPositionX();
	int getPositionY();
	void toString();
};

