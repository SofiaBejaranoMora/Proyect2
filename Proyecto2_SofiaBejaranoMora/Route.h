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
	GeneralList<Point>* pointsList;
	Color color;
public:
	Route(string name,GeneralList<Point>* pointsList,Color color);

};

