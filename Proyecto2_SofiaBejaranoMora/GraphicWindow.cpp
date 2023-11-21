#include "GraphicWindow.h"

GraphicWindow::GraphicWindow()
{
	listManager = new ListManager;
	nameRoute = " ";
	enabledAddPoint = false;
	enabledSelectionRoute = false;
	enabledSelectionPoint = false;
	enabledSelectionPoint = false;
	enabledShow = false;
	enabledHide=false;
	enabledAutoSave = false;
	selectedPoint = new Point;
	selectedRoute = new Route;
	lastX = 0;
	lastY = 0;
}

void GraphicWindow::windowMap()
{
	RenderWindow windowMap(VideoMode(1366, 778), "Map", Style::None);
	
	bool enabledReset= false;

	Texture imageWindowMap;
	Texture imageButtonExit;
	Texture imageRouteMenu;
	Texture imageButtonAdd;
	Texture imageFinishRoutebutton;
	Texture imageButtonSave;
	Texture imageButtonLoad;
	Texture imageButtonSelectionRoute;
	Texture imageButtonHide;
	Texture imageButtonDelete;
	Texture imageButtonSelectionPoint;
	Texture imageButtonShow;
	Texture imagePointMenu;
	Texture imagenSaveMode;
	Texture imagenButtonAutomaticSaveButton;
	Texture imageManualSaveButton;
	Texture imageResetButton;

	if (!imageWindowMap.loadFromFile("Images/Map.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonExit.loadFromFile("Images/ButtonExit.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageRouteMenu.loadFromFile("Images/RouteMenu.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonAdd.loadFromFile("Images/addButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageFinishRoutebutton.loadFromFile("Images/finishRoutebutton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonSave.loadFromFile("Images/saveButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonLoad.loadFromFile("Images/loadButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonSelectionRoute.loadFromFile("Images/selectionRouteButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonHide.loadFromFile("Images/hideButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonDelete.loadFromFile("Images/deleteButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonSelectionPoint.loadFromFile("Images/selectionPointButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageButtonShow.loadFromFile("Images/showButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imagePointMenu.loadFromFile("Images/PointMenu.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imagenSaveMode.loadFromFile("Images/saveMode.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imagenButtonAutomaticSaveButton.loadFromFile("Images/automaticSaveButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageManualSaveButton.loadFromFile("Images/manualSaveButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}
	if (!imageResetButton.loadFromFile("Images/resetButton.png")) {
		throw ERROR_OPEN_IMAGE;
	}

	Sprite sprImageWindowMap(imageWindowMap);
	Sprite sprImageButtonExit(imageButtonExit);
	Sprite sprImageRouteMenu(imageRouteMenu);
	Sprite sprImageButtonAdd(imageButtonAdd);
	Sprite sprImageFinishRoutebutton(imageFinishRoutebutton);
	Sprite sprImageButtonSave(imageButtonSave);
	Sprite sprImageButtonLoad(imageButtonLoad);
	Sprite sprImageButtonSelectionRoute(imageButtonSelectionRoute);
	Sprite sprImageButtonHide(imageButtonHide);
	Sprite sprImageButtonDelete(imageButtonDelete);
	Sprite sprImageButtonSelectionPoint(imageButtonSelectionPoint);
	Sprite sprImageButtonShow(imageButtonShow);
	Sprite sprImagePointMenu(imagePointMenu);
	Sprite sprImagenSaveMode(imagenSaveMode);
	Sprite sprImagenButtonAutomaticSaveButton(imagenButtonAutomaticSaveButton);
	Sprite sprImageManualSaveButton(imageManualSaveButton);
	Sprite sprImageResetButton(imageResetButton);

	sprImageButtonExit.setPosition(30, 40);
	sprImageResetButton.setPosition(1220,40);
	sprImageFinishRoutebutton.setPosition(1220, 150);
	sprImageButtonDelete.setPosition(1220, 227);
	sprImageButtonShow.setPosition(1220, 284);
	sprImageButtonHide.setPosition(1220, 334);
	sprImagenSaveMode.setPosition(1220, 434);
	sprImagenButtonAutomaticSaveButton.setPosition(1220, 532);
	sprImageManualSaveButton.setPosition(1220, 562);
	sprImageRouteMenu.setPosition(30, 170);
	sprImageButtonAdd.setPosition(30, 253);
	sprImageButtonLoad.setPosition(30, 298);
	sprImageButtonSelectionRoute.setPosition(30, 346);
	sprImageButtonSave.setPosition(30, 394);
	sprImagePointMenu.setPosition(30, 535);
	sprImageButtonSelectionPoint.setPosition(30, 629);

	sprImageWindowMap.setScale(static_cast<float>(windowMap.getSize().x) / sprImageWindowMap.getLocalBounds().width,
		static_cast<float>(windowMap.getSize().y) / sprImageWindowMap.getLocalBounds().height);

	while (windowMap.isOpen()) {
		Event eventWindowMap;


		while (windowMap.pollEvent(eventWindowMap)) {
			if ((enabledAutoSave)&&(!enabledReset)) {
				listManager->saveListRoute();
			}
			enabledReset = false;
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
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left) && (enabledAddPoint)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				int x = eventWindowMap.mouseButton.x;
				int y = eventWindowMap.mouseButton.y;
				if (((195 < x) && (x < 1200)) && ((x != lastX) && (y != lastY))) {
					enterData(x, y);
					lastX = x;
					lastY = y;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if ((sprImageFinishRoutebutton.getGlobalBounds().contains(mousePosition))) {
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
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (((sprImageButtonSelectionPoint.getGlobalBounds().contains(mousePosition)))) {
					enabledSelectionPoint = true;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (((sprImageButtonSelectionRoute.getGlobalBounds().contains(mousePosition)))) {
					enabledSelectionRoute = true;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)
				&& ((enabledSelectionPoint) || (enabledSelectionRoute))) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				int x = eventWindowMap.mouseButton.x;
				int y = eventWindowMap.mouseButton.y;
				if ((195 < x) && (x < 1200)) {
					if (enabledSelectionPoint) {
						selectedPoint = listManager->searchPoint(x, y);
					}
					if ((enabledSelectionRoute) || (enabledHide) || (enabledShow)) {
						selectedRoute = listManager->searchRoute(x, y);
					}
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (((sprImageButtonDelete.getGlobalBounds().contains(mousePosition)))) {
					if (enabledSelectionPoint) {
						listManager->deletePoint(selectedPoint);
						enabledSelectionPoint = false;
					}
					if (enabledSelectionRoute) {
						listManager->deleteRoute(selectedRoute);
						enabledSelectionRoute = false;
					}
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (((sprImageButtonShow.getGlobalBounds().contains(mousePosition)))) {
					if (selectedRoute) {
						selectedRoute->setIsVisible(true);
						selectedRoute = new Route;
					}
					enabledSelectionRoute = false;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (((sprImageButtonHide.getGlobalBounds().contains(mousePosition)))) {
					if (selectedRoute) {
						selectedRoute->setIsVisible(false);
						selectedRoute = new Route;
					}
					enabledSelectionRoute = false;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (sprImagenButtonAutomaticSaveButton.getGlobalBounds().contains(mousePosition)) {
					enabledAutoSave = true;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (sprImageManualSaveButton.getGlobalBounds().contains(mousePosition)) {
					enabledAutoSave = false;
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (sprImageResetButton.getGlobalBounds().contains(mousePosition)) {
					enabledReset= true;
					listManager->deletelistRoute();
				}
			}

		}

		windowMap.clear();
		windowMap.draw(sprImageWindowMap);
		if ((!enabledAddPoint) && (!enabledSelectionPoint) && (!enabledSelectionRoute)) {
			windowMap.draw(sprImagenSaveMode);
			windowMap.draw(sprImageButtonExit);
			windowMap.draw(sprImageRouteMenu);
			windowMap.draw(sprImageButtonAdd);
			windowMap.draw(sprImageButtonLoad);
			windowMap.draw(sprImageButtonSelectionRoute);
			windowMap.draw(sprImagePointMenu);
			windowMap.draw(sprImageButtonSelectionPoint);
			windowMap.draw(sprImageResetButton);
			if (!enabledAutoSave) {
				windowMap.draw(sprImageButtonSave);
				windowMap.draw(sprImagenButtonAutomaticSaveButton);
			}
			else {
				windowMap.draw(sprImageManualSaveButton);
			}
		}
		if ((enabledAddPoint) && (listManager->getListRoute()->getHead()->getData()->getPointsList()->getHead()!=nullptr)) {
			windowMap.draw(sprImageFinishRoutebutton);
		}

		if (enabledSelectionRoute) {
			windowMap.draw(sprImageButtonDelete);
			windowMap.draw(sprImageButtonShow);
			windowMap.draw(sprImageButtonHide);
			drawNameSelectedRoute(windowMap);
		}
		if (enabledSelectionPoint) {
			windowMap.draw(sprImageButtonDelete);
			drawNameSelectedRoute(windowMap);
		}
		drawRoute(windowMap);
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
	system("cls");
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
			DoubleNode<Point>* currentNodePoint = currentNodeRoute->getData()->getPointsList()->getHead();
			if (currentNodeRoute->getData()->getIsVisible() == false) {
				drawHiddenRoute(window, currentNodeRoute);
			}
			else {
				Color color = currentNodeRoute->getData()->getColor();
				if (currentNodeRoute->getData() == selectedRoute) {
					color = Color::Green;
				}
				drawPoint(window, currentNodePoint, color);
			}
			currentNodeRoute = currentNodeRoute->getNext();
		}
	}
}

void GraphicWindow::drawHiddenRoute(RenderWindow& window, DoubleNode<Route>* route)
{
	Color color = route->getData()->getColor();
	if (route->getData() == selectedRoute) {
		color = Color::Green;
	}
	Point* point = route->getData()->getPointsList()->getHead()->getData();
	RectangleShape Rectangle(Vector2f(10.0f, 10.0f));
	Rectangle.setFillColor(color);
	Rectangle.setPosition(point->getPositionX()-4, point->getPositionY()-4);
	window.draw(Rectangle);
}

void GraphicWindow::drawPoint(RenderWindow& window, DoubleNode<Point>* currentNodePoint,Color color)
{
	if (currentNodePoint) {
		Vertex line[2];
		CircleShape circle;
		circle.setRadius(5);
		while (currentNodePoint) {
			circle.setFillColor(color);
			if (selectedPoint == currentNodePoint->getData()) {
				circle.setFillColor(Color::Green);
			}
			if(currentNodePoint->getNext()){
				line[0] = Vertex(Vector2f(currentNodePoint->getData()->getPositionX(),
					currentNodePoint->getData()->getPositionY()), color);
				line[1]=Vertex(Vector2f(currentNodePoint->getNext()->getData()->getPositionX(),
					currentNodePoint->getNext()->getData()->getPositionY()), color);
			}
			circle.setPosition(currentNodePoint->getData()->getPositionX()-4, currentNodePoint->getData()->getPositionY()-4);
			window.draw(line, 2, Lines);
			window.draw(circle);
			currentNodePoint = currentNodePoint->getNext();
		}
	}
}

void GraphicWindow::drawNameSelectedRoute(RenderWindow& window)
{
	if (enabledSelectionRoute || enabledSelectionPoint) {
		Color color(255, 253, 95);
		Font source;
		if (!source.loadFromFile("Overthink.ttf")) {
			throw 3;
		}
		Text nameRoute("", source, 35);
		if (selectedRoute!=nullptr) {
			nameRoute.setString("name Route:\n" + selectedRoute->getName());
		}
		if (selectedPoint != nullptr) {
			Route* route = listManager->searchRoute(selectedPoint->getPositionX(), selectedPoint->getPositionY());
			if (route) {
				nameRoute.setString("name Route:\n" + route->getName());
			}
		}
		nameRoute.setFillColor(color);
		nameRoute.setPosition(1190, 90);
		window.draw(nameRoute);
	}
}

Color GraphicWindow::colorRoute()
{
	Color color;

	RenderWindow windowColorPalette(VideoMode(700, 243), "ColorPalette", Style::None);

	Texture imageColorPalette;

	if (!imageColorPalette.loadFromFile("Images/colorPalette.png")) {
		throw ERROR_OPEN_IMAGE;
	}

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

int GraphicWindow::getERROR_OPEN_IMAGE()
{
	return ERROR_OPEN_IMAGE;
}



