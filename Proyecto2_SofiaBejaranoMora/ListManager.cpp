#include "ListManager.h"

ListManager::ListManager()
{
	listRoute = new GeneralList<Route>;
	currentRoute = new Route;
}

void ListManager::setCurrentRoute(Route* currentRoute)
{
	this->currentRoute = currentRoute;
}

void ListManager::addRoute()
{
	listRoute->insertEnd(currentRoute);
}

void ListManager::insertPoint(int x, int y)
{
	currentRoute->addPoint(x, y);
}

GeneralList<Route>* ListManager::getListRoute()
{
	return listRoute;
}

Route* ListManager::getCurrentRoute()
{
	return currentRoute;
}
