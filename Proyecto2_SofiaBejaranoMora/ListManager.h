#pragma once
#include "Route.h"
#include "GeneralList.h"

class ListManager
{
private:
	GeneralList<Route>* listRoute;
	Route* currentRoute;

public:
	ListManager();
	void setCurrentRoute(Route* currentRoute);
	void addRoute();
	void insertPoint(int x, int y);
	GeneralList<Route>* getListRoute();
	Route* getCurrentRoute();
};

