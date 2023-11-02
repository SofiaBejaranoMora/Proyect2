#include <iostream>
#include "GraphicWindow.h"
#include "GeneralList.h"
#include "Point.h"
#include "Route.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "ListManager.h"
#include"DoubleNode.h"

int main()
{
	/*ListManager* route = new ListManager;
	
	int opcion = 0, opcion2 = 0;
	int x = 0, y = 0;
	string nombre;
	while (opcion!=9) {
		cout << "Nombre de ruta" << endl;
		cin >> nombre;
		Route* ruta1 = new Route(nombre);
		route->setCurrentRoute(ruta1);
		while (opcion2 != 7) {
			cout << "ingrese x " << endl;
			cin >> x;
			cout << "ingrese y " << endl;
			cin >> y;
			cout << "salie 7" << endl;
			cin >> opcion2;
			route->insertPoint(x, y);
		}
		opcion2 = 0;
		route->addRoute();
		cout << "salie 9" << endl;
		cin >> opcion;
	}
	DoubleNode<Route>* cR = route->getListRoute()->getHead();
	while (cR) {
		cR->getData()->toString();
		DoubleNode<Point>* cP = cR->getData()->getPointsList()->getHead();
		while (cP) {
			cout << cP->getData()->getPositionX() << endl;
			cout << cP->getData()->getPositionY() << endl;
			cP = cP->getNext();
		}
		cR = cR->getNext();
	}*/
	
	
	GraphicWindow window;
	window.windowMap();

	//ListManager* l = new ListManager;
	//l->setCurrentRoute(new Route("holi"));
	//l->getCurrentRoute()->toString();

	//GeneralList<Route>* p;


}
