#pragma once
#include "Route.h"
#include "GeneralList.h"
#include "FileManager.h"

class ListManager
{
private:
	GeneralList<Route>* listRoute;
	Route* currentRoute;
	FileManager* fileManager;
public:
	ListManager();
	void deletelistRoute();
	void setCurrentRoute(Route* currentRoute);
	void addRoute();
	void insertPoint(int x, int y);
	void saveListRoute();
	void loadListRoute();
	void deleteRoute(Route* route);
	void deletePoint(Point* point);
	Route* searchRoute(int x, int y);
	Point* searchPoint(int x, int y);
	GeneralList<Route>* getListRoute();
	Route* getCurrentRoute();
};

