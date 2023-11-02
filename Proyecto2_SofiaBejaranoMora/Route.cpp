#include "Route.h"

Route::Route()
{
}

Route::Route(string name)
{
	this->name = name;
	pointList = new GeneralList<Point>;
}

Route::Route(string name, GeneralList<Point>* pointsList/*,Color color*/)
{
	this->name = name;
	this->pointList = pointsList;
	//this->color = color;
}

GeneralList<Point>* Route::getPointsList()
{
	return pointList;
}

void Route::addPoint(int x, int y)
{
	pointList->insertEnd(new Point(x, y));
}

void Route::setPointsList(GeneralList<Point>* pointsList)
{
	this->pointList = pointsList;
}

void Route::toString()
{
	cout << name << endl;
}
