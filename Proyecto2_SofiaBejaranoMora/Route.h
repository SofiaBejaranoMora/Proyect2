#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "GeneralList.h"

using namespace std;
using namespace sf;

class Route
{
private:
	string name; 
	GeneralList<Point>* pointList;
	bool isVisible;
	Color color;
public:
	Route();
	Route(string name);
	GeneralList<Point>* getPointsList();
	string getName();
	Color getColor();
	Point* searchPoint(int x, int y);
	bool getIsVisible();
	bool checkedPoint(int x, int y);
	bool deletePoint(Point* point);
	void addPoint(int x, int y);
	void setPointsList(GeneralList<Point>* pointsList);
	void setColor(Color color);
	void setName(string name);
	void setIsVisible(bool isVisible);
};
 
 
 
 

