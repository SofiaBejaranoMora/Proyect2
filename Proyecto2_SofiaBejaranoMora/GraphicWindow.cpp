#include "GraphicWindow.h"

GraphicWindow::GraphicWindow()
{
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
	Texture imagenButtonExit;
	Texture imagenButtonAddRoute;

	imageWindowMap.loadFromFile("Images/Map.png");
	imagenButtonExit.loadFromFile("Images/ButtonExit.png");
	imagenButtonAddRoute.loadFromFile("Images/AddRouteButton.png");

	Sprite sprImageWindowMap(imageWindowMap);
	Sprite sprImagenButtonExit(imagenButtonExit);
	Sprite sprImagenButtonAddRoute(imagenButtonAddRoute);

	sprImagenButtonExit.setPosition(30, 40);
	sprImagenButtonAddRoute.setPosition(30, 90);

	sprImageWindowMap.setScale(static_cast<float>(windowMap.getSize().x) / sprImageWindowMap.getLocalBounds().width,
		static_cast<float>(windowMap.getSize().y) / sprImageWindowMap.getLocalBounds().height);

	while (windowMap.isOpen()) {
		Event eventWindowMap;
		while (windowMap.pollEvent(eventWindowMap)) {
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (sprImagenButtonExit.getGlobalBounds().contains(mousePosition)) {
					windowMap.close();
				}
			}
			if ((eventWindowMap.type == Event::MouseButtonPressed) && (eventWindowMap.mouseButton.button == Mouse::Left)) {
				Vector2f mousePosition = windowMap.mapPixelToCoords(Mouse::getPosition(windowMap));
				if (sprImagenButtonAddRoute.getGlobalBounds().contains(mousePosition)) {
					windowMap.close();
				}
			}
		}
		windowMap.draw(sprImageWindowMap);
		windowMap.draw(sprImagenButtonExit);
		windowMap.draw(sprImagenButtonAddRoute);
		/*windowMap.draw(linea, 2, Lines);*/
		windowMap.display();
	}

}