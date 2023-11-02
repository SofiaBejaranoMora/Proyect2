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
	string nameRoute;
	ListManager* listManager;
public:
	GraphicWindow();
	void windowMap();
	void enterData(int x, int y);
	void useConsole();
	void drawRoute(RenderWindow& window);

};

