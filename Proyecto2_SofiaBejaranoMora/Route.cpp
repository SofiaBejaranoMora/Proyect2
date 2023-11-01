#include "Route.h"

Route::Route(string name)
{
	this->name = name;
}

Route::Route(string name, GeneralList<Point>* pointsList/*,Color color*/)
{
	this->name = name;
	this->pointsList = pointsList;
	//this->color = color;
}

GeneralList<Point>* Route::getPointsList()
{
	return pointsList;
}

void Route::setPointsList(GeneralList<Point>* pointsList)
{
	this->pointsList = pointsList;
}

void Route::toString()
{
	cout << name << endl;
	pointsList->imprimir();
}
