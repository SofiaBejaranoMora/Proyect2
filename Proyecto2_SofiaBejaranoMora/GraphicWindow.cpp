#include "GraphicWindow.h"

GraphicWindow::GraphicWindow()
{
	listManager = new ListManager;
	nameRoute = " ";
	enabledAddPoint = false;
}

void GraphicWindow::windowMap()
{
	Color colorRed(255, 0, 0);
	Color Blue(0, 0, 225);
	string colorBlue = "Blue";
	RenderWindow windowMap(VideoMode(1366, 778), "Map", Style::None);

	/*Vertex linea[] = {
		Vertex(Vector2f(100,100),colorRed),
		Vertex(Vector2f(300,300),colorRed)
	};*/

	Texture imageWindowMap;
	Texture imageButtonExit;
	Texture imageRoute;
	Texture imageButtonAdd;
	Texture imageButtonReady;

	imageWindowMap.loadFromFile("Images/Map.png");
	imageButtonExit.loadFromFile("Images/ButtonExit.png");
	imageRoute.loadFromFile("Images/Route.png");
	imageButtonAdd.loadFromFile("Images/addButton.png");
	imageButtonReady.loadFromFile("Images/readyButton.png");

	Sprite sprImageWindowMap(imageWindowMap);
	Sprite sprImageButtonExit(imageButtonExit);
	Sprite sprImageRoute(imageRoute);
	Sprite sprImageButtonAdd(imageButtonAdd);
	Sprite sprImageButtonReady(imageButtonReady);

	sprImageButtonExit.setPosition(30, 40);
	sprImageRoute.setPosition(30, 120);
	sprImageButtonAdd.setPosition(30, 163);//Todas las imagenes que tengan que ver con ruta llevan 10 mp de distancia 
	sprImageButtonReady.setPosition(1250, 90);

	sprImageWindowMap.setScale(static_cast<float>(windowMap.getSize().x) / sprImageWindowMap.getLocalBounds().width,
		static_cast<float>(windowMap.getSize().y) / sprImageWindowMap.getLocalBounds().height);

	while (windowMap.isOpen()) {
		Event eventWindowMap;
		while (windowMap.pollEvent(eventWindowMap)) {
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (sprImageButtonExit.getGlobalBounds().contains(mousePosition)) {
					windowMap.close();
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if ((sprImageButtonAdd.getGlobalBounds().contains(mousePosition)) && (!enabledAddPoint)) {
					useConsole();
					listManager->setCurrentRoute(new Route(nameRoute));
					listManager->addRoute();
					enabledAddPoint = true;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)&& (enabledAddPoint)) {
				if (enabledAddPoint) {
					int x = eventWindowMap.mouseButton.x;
					int y = eventWindowMap.mouseButton.y;
					enterData(x, y);
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if ((sprImageButtonReady.getGlobalBounds().contains(mousePosition))) {
					enabledAddPoint = false;

				}
			}

		}
		windowMap.draw(sprImageWindowMap);
		windowMap.draw(sprImageButtonExit);
		windowMap.draw(sprImageRoute);
		windowMap.draw(sprImageButtonAdd);
		drawRoute(windowMap);
		if (enabledAddPoint) {
			windowMap.draw(sprImageButtonReady);
		}
		windowMap.display();
	}
}

void GraphicWindow::enterData(int x,int y)
{
	listManager->insertPoint(x, y);
}

void GraphicWindow::useConsole()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MINIMIZE);
	cout << "Ingrese el nombre de la ruta que va a crear: ";
	ShowWindow(hwnd, SW_RESTORE);
	cin >> nameRoute;
	ShowWindow(hwnd, SW_MINIMIZE);

}

void GraphicWindow::drawRoute(RenderWindow& window)
{
	Color colorRed(255, 0, 0);
	if (listManager->getListRoute()->getHead()) {
		GeneralList<Route>* listRoute = listManager->getListRoute();
		DoubleNode<Route>* currentNodeRoute = listRoute->getHead();
		while (currentNodeRoute) {
			Route* Route = currentNodeRoute->getData();
			DoubleNode<Point>* currentNodePoint = Route->getPointsList()->getHead();
			while (currentNodePoint->getNext()) {
				Vertex linea[] = {
					Vertex(Vector2f(currentNodePoint->getData()->getPositionX(),
						currentNodePoint->getData()->getPositionY()),colorRed),
					Vertex(Vector2f(currentNodePoint->getNext()->getData()->getPositionX(),
						currentNodePoint->getNext()->getData()->getPositionY()),colorRed)
				};
				window.draw(linea, 2, Lines);
				currentNodePoint = currentNodePoint->getNext();
			}
			currentNodeRoute = currentNodeRoute->getNext();
		}
	}
}




