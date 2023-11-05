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
	Color color;
public:
	Route();
	Route(string name);
	Route(string name,GeneralList<Point>* pointsList);
	GeneralList<Point>* getPointsList();
	string getName();
	Color getColor();
	void addPoint(int x, int y);
	void setPointsList(GeneralList<Point>* pointsList);
	void setColor(Color color);
	void setName(string name);
	void toString();
};

