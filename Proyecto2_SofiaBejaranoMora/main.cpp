#include <iostream>
#include "GraphicWindow.h"
#include "GeneralList.h"
#include "Point.h"
#include "Route.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
	/*GeneralList<Route> route;
	int opcion = 0, opcion2 = 0;
	int x = 0, y = 0;
	string nombre;
	while (opcion!=9) {
		cout << "Nombre de ruta" << endl;
		cin >> nombre;
		Route* ruta1 = new Route(nombre);
		GeneralList<Point>* pointList = new GeneralList<Point>;
		while (opcion2 != 7) {
			cout << "ingrese x " << endl;
			cin >> x;
			cout << "ingrese y " << endl;
			cin >> y;
			cout << "salie 7" << endl;
			cin >> opcion2;
			pointList->insertEnd(new Point(x, y));
		}
		opcion2 = 0;
		ruta1->setPointsList(pointList);
		route.insertEnd(ruta1);
		cout << "salie 9" << endl;
		cin >> opcion;
	}
	route.imprimir();*/
	
	HWND hwnd = GetConsoleWindow();
	GraphicWindow window (hwnd);
	window.windowMap();

	
	
}
