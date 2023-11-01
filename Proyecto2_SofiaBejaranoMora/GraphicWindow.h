#pragma once
#include<iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;
using namespace std;

class GraphicWindow
{
private:
	bool enabledAddPoint;
	HWND hwnd;
	string nameRoute;
public:
	GraphicWindow(HWND hwnd);
	void windowMap();
	void enterData();
	void useConsole();
};

