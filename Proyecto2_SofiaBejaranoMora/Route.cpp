#include "Route.h"

Route::Route()
{
	name = "";
	pointList = new GeneralList<Point>;
	color = Color::Transparent;
	isVisible = true;
}

Route::Route(string name)
{
	this->name = name;
	pointList = new GeneralList<Point>;
	color = Color::Transparent;
	isVisible = true;
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

Point* Route::searchPoint(int x, int y)
{
	DoubleNode<Point>* current = pointList->getHead();
	while (current) {
		if (current->getData()->checkTouch(x, y)) {
			return current->getData();
		}
		current = current->getNext();
	}
	return nullptr;
}

bool Route::getIsVisible()
{
	return isVisible;
}

bool Route::checkedPoint(int x, int y)
{
	DoubleNode<Point>* current = pointList->getHead();
	while (current) {
		if (current->getData()->checkTouch(x, y)) {
			return true;
		}
		current = current->getNext();
	}
	return false;
}

bool Route::deletePoint(Point* point)
{
	DoubleNode<Point>* current = pointList->getHead();
	while (current) {
		if (pointList->deleteData(point)) {
			return true;
		}
		current = current->getNext();
	}
	return false;
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

void Route::setIsVisible(bool isVisible)
{
	this->isVisible = isVisible;
}


