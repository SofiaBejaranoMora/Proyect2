#include "Route.h"

Route::Route(string name, GeneralList<Point>* pointsList,Color color)
{
	this->name = name;
	this->pointsList = pointsList;
	this->color = color;
}
