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
	void setCurrentRoute(Route* currentRoute);
	void addRoute();
	void insertPoint(int x, int y);
	void saveListRoute();
	void loadListRoute();
	GeneralList<Route>* getListRoute();
	Route* getCurrentRoute();
};

