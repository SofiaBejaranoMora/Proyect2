#include "ListManager.h"

ListManager::ListManager()
{
	listRoute = new GeneralList<Route>;
	currentRoute = new Route;
	fileManager = new FileManager;
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

void ListManager::saveListRoute()
{
	fileManager->saveList(listRoute);
}

GeneralList<Route>* ListManager::getListRoute()
{
	return listRoute;
}

Route* ListManager::getCurrentRoute()
{
	return currentRoute;
}
