#include "GraphicWindow.h"

GraphicWindow::GraphicWindow()
{
	listManager = new ListManager;
	nameRoute = " ";
	enabledAddPoint = false;
	lastX = 0;
	lastY = 0;
}

void GraphicWindow::windowMap()
{
	
	RenderWindow windowMap(VideoMode(1366, 778), "Map", Style::None);

	Texture imageWindowMap;
	Texture imageButtonExit;
	Texture imageRoute;
	Texture imageButtonAdd;
	Texture imageButtonReady;
	Texture imageButtonSave;
	Texture imageButtonLoad;

	imageWindowMap.loadFromFile("Images/Map.png");
	imageButtonExit.loadFromFile("Images/ButtonExit.png");
	imageRoute.loadFromFile("Images/Route.png");
	imageButtonAdd.loadFromFile("Images/addButton.png");
	imageButtonReady.loadFromFile("Images/readyButton.png");
	imageButtonSave.loadFromFile("Images/saveButton.png");
	imageButtonLoad.loadFromFile("Images/loadButton.png");
	

	Sprite sprImageWindowMap(imageWindowMap);
	Sprite sprImageButtonExit(imageButtonExit);
	Sprite sprImageRoute(imageRoute);
	Sprite sprImageButtonAdd(imageButtonAdd);
	Sprite sprImageButtonReady(imageButtonReady);
	Sprite sprImageButtonSave(imageButtonSave);
	Sprite sprImageButtonLoad(imageButtonLoad);

	sprImageButtonExit.setPosition(30, 40);
	sprImageButtonReady.setPosition(1250, 90);
	sprImageRoute.setPosition(30, 120);
	sprImageButtonAdd.setPosition(30, 163);//Todas las imagenes que tengan que ver con ruta llevan 10 mp de distancia 
	sprImageButtonSave.setPosition(30, 211);
	sprImageButtonLoad.setPosition(30, 257);
	

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
					listManager->getCurrentRoute()->setColor(colorRoute());
					enabledAddPoint = true;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)&& (enabledAddPoint)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				int x = eventWindowMap.mouseButton.x;
				int y = eventWindowMap.mouseButton.y;
				if (((130 < x) && (x < 1200))&&((x != lastX)&&(y!=lastY))) {
					enterData(x, y);
					lastX = x;
					lastY = y;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if ((sprImageButtonReady.getGlobalBounds().contains(mousePosition))) {
					enabledAddPoint = false;

				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if ((sprImageButtonSave.getGlobalBounds().contains(mousePosition))) {
					listManager->saveListRoute();
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if ((sprImageButtonLoad.getGlobalBounds().contains(mousePosition))) {
					listManager->loadListRoute();
				}
			}

		}

		windowMap.clear();
		windowMap.draw(sprImageWindowMap);
		windowMap.draw(sprImageButtonExit);
		windowMap.draw(sprImageRoute);
		windowMap.draw(sprImageButtonAdd);
		windowMap.draw(sprImageButtonSave);
		windowMap.draw(sprImageButtonLoad);
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
	if (listManager->getListRoute()->getHead()) {
		GeneralList<Route>* listRoute = listManager->getListRoute();
		DoubleNode<Route>* currentNodeRoute = listRoute->getHead();
		while (currentNodeRoute) {
			Route* Route = currentNodeRoute->getData();
			DoubleNode<Point>* currentNodePoint = Route->getPointsList()->getHead();

			drawPoint(window, currentNodePoint,currentNodeRoute->getData()->getColor());

			currentNodeRoute = currentNodeRoute->getNext();
		}
	}
}

void GraphicWindow::drawPoint(RenderWindow& window, DoubleNode<Point>* currentNodePoint,Color color)
{
	if (currentNodePoint) {
		while (currentNodePoint->getNext()) {
			Vertex line[] = {
				Vertex(Vector2f(currentNodePoint->getData()->getPositionX(),
					currentNodePoint->getData()->getPositionY()),color),
				Vertex(Vector2f(currentNodePoint->getNext()->getData()->getPositionX(),
					currentNodePoint->getNext()->getData()->getPositionY()),color)
			};
			window.draw(line, 2, Lines);
			currentNodePoint = currentNodePoint->getNext();
		}
	}
}

Color GraphicWindow::colorRoute()
{
	Color color;

	RenderWindow windowColorPalette(VideoMode(700, 263), "ColorPalette", Style::None);

	Texture imageColorPalette;

	imageColorPalette.loadFromFile("Images/colorPalette.png");

	Sprite sprImageColorPalette(imageColorPalette);

	sprImageColorPalette.setScale(static_cast<float>(windowColorPalette.getSize().x) / sprImageColorPalette.getLocalBounds().width,
		static_cast<float>(windowColorPalette.getSize().y) / sprImageColorPalette.getLocalBounds().height);

	while (windowColorPalette.isOpen()) {
		Event eventWindowColorPalette;
		while (windowColorPalette.pollEvent(eventWindowColorPalette)) {
			if ((eventWindowColorPalette.type == Event::MouseButtonPressed) && (eventWindowColorPalette.mouseButton.button == Mouse::Left)) {
				Vector2i posicionMouse = Mouse::getPosition(windowColorPalette);
				color = imageColorPalette.copyToImage().getPixel(posicionMouse.x, posicionMouse.y);
				windowColorPalette.close();
			}
		}
		windowColorPalette.clear();
		windowColorPalette.draw(sprImageColorPalette);
		windowColorPalette.display();
	}
	return color;
}



