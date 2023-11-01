#include "GraphicWindow.h"

GraphicWindow::GraphicWindow(HWND hwnd)
{
	this->hwnd = hwnd;
	enabledAddPoint = false;
	nameRoute = " ";
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
				if ((sprImageButtonAdd.getGlobalBounds().contains(mousePosition))&&(!enabledAddPoint)) {
					useConsole();
					enabledAddPoint = true;
				}
			}
			if (((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left))&&(enabledAddPoint)){
				int x = eventWindowMap.mouseButton.x;
				int y = eventWindowMap.mouseButton.y;
			}
		}
		windowMap.draw(sprImageWindowMap);
		windowMap.draw(sprImageButtonExit);
		windowMap.draw(sprImageRoute);
		windowMap.draw(sprImageButtonAdd);
		/*windowMap.draw(linea, 2, Lines);*/
		windowMap.display();
	}

}

void GraphicWindow::enterData()
{

}

void GraphicWindow::useConsole()
{
	system("cls");
	ShowWindow(hwnd, SW_MINIMIZE);
	cout << "Ingrese el nombre de la ruta que va a crear: \n";
	ShowWindow(hwnd, SW_RESTORE);
	cin >> nameRoute;
	ShowWindow(hwnd, SW_MINIMIZE);
	system("pause");
}
