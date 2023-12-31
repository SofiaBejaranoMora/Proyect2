#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "ListManager.h"
#include "GeneralList.h"
#include"DoubleNode.h"

using namespace sf;
using namespace std;

class GraphicWindow
{
private:
	bool enabledAddPoint;
	bool enabledSelectionRoute;
	bool enabledSelectionPoint;
	bool enabledShow;
	bool enabledHide;
	bool enabledAutoSave;
	string nameRoute;
	ListManager* listManager;
	Point* selectedPoint;
	Route* selectedRoute;
	int lastX;
	int lastY;
	const int ERROR_OPEN_IMAGE = 1;
public:
	GraphicWindow();
	void windowMap();
	void enterData(int x, int y);
	void useConsole();
	void drawRoute(RenderWindow& window);
	void drawHiddenRoute(RenderWindow& window, DoubleNode<Route>* route);
	void drawPoint(RenderWindow& window, DoubleNode<Point>* currentNodePoint, Color color);
	void drawNameSelectedRoute(RenderWindow& window);
	Color colorRoute();
	int getERROR_OPEN_IMAGE();
};

