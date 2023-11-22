#include "ListManager.h"

ListManager::ListManager()
{
	listRoute = new GeneralList<Route>;
	currentRoute = new Route;
	fileManager = new FileManager;
}

void ListManager::deletelistRoute()
{
	if (listRoute->getHead()) {//NOTE:puede mejorar su codigo invirtiendo el if, y usando un early return
		DoubleNode<Route>* current = listRoute->getLast();
		while (current->getPrevious()) {
			current = current->getPrevious();
			listRoute->deleteEnd();
		}
		listRoute->deleteEnd();
	}
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

void ListManager::loadListRoute()
{
	listRoute = fileManager->loadList();
}

void ListManager::deleteRoute(Route* route)
{
	DoubleNode<Route>* current = listRoute->getHead();
	while (current) {
		if (listRoute->deleteData(route)) {
			break;
		}
		current = current->getNext();
	}
	
}

void ListManager::deletePoint(Point* point)
{
	DoubleNode<Route>* current = listRoute->getHead();
	while (current) {
		if (current->getData()->deletePoint(point)) {
			break;
		}
		current = current->getNext();
	}
}

Route* ListManager::searchRoute(int x, int y)
{
	DoubleNode<Route>* current = listRoute->getHead();
	while (current) {
		if (current->getData()->checkedPoint(x, y)) {
			return current->getData();
		}
		current = current->getNext();
	}
	return nullptr;
}

Point* ListManager::searchPoint(int x, int y)
{
	DoubleNode<Route>* current = listRoute->getHead();
	while (current) {
		if (current->getData()->checkedPoint(x,y)) {
			return current->getData()->searchPoint(x,y);
		}
		current = current->getNext();
	}
	return nullptr;
}

GeneralList<Route>* ListManager::getListRoute()
{
	return listRoute;
}

Route* ListManager::getCurrentRoute()
{
	return currentRoute;
}
