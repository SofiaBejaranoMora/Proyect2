#include <iostream>
#include "GraphicWindow.h"
#include "GeneralList.h"
#include "Point.h"
#include "Route.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "ListManager.h"
#include "DoubleNode.h"

int main()
{
	GraphicWindow window;
	try {
		window.windowMap();
	}
	catch (int exceptionId) {
		if (window.getERROR_OPEN_IMAGE() == 1) {
			cout << "Could not find the images, check that the address is correct" << endl;
		}
		else if (exceptionId == 2) {
			cout << "there is an error when opening the file"<<endl;
		}
		else if (exceptionId == 3) {
			cout << "there is an error loading the font" << endl;
		}
		else {
			cout << "Unknown error" << endl;
		}
	}
}
