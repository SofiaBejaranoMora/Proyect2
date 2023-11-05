#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "GeneralList.h"
#include "DoubleNode.h"
#include "Route.h"

using namespace std;

class FileManager
{
private:
	string name;
public:
	FileManager();
	void saveList(GeneralList<Route>* listManager);
	string serializeRoute(Route* route);
	string serializeColor(Color color);
	string serializeListPoint(GeneralList<Point>* listPoint);
	GeneralList<Route>* saveList();
};

