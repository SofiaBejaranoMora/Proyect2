#include "Route.h"

Route::Route()
{
	name = "";
	pointList = new GeneralList<Point>;
	color = Color::Transparent;
}

Route::Route(string name)
{
	this->name = name;
	pointList = new GeneralList<Point>;
	color = Color::Transparent;
}

Route::Route(string name, GeneralList<Point>* pointsList/*,Color color*/)
{
	this->name = name;
	this->pointList = pointsList;
	color =Color::Transparent;
}

GeneralList<Point>* Route::getPointsList()
{
	return pointList;
}

string Route::getName()
{
	return name;
}

Color Route::getColor()
{
	return color;
}

void Route::addPoint(int x, int y)
{
	pointList->insertEnd(new Point(x, y));
}

void Route::setPointsList(GeneralList<Point>* pointsList)
{
	this->pointList = pointsList;
}

void Route::setColor(Color color)
{
	this->color = color;
}

void Route::setName(string name)
{
	this->name = name;
}

void Route::toString()
{
	cout << name << endl;
}
