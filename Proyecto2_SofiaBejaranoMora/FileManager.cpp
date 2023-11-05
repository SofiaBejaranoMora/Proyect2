#include "FileManager.h"

FileManager::FileManager()
{
	name = "routeFile.txt";
}

void FileManager::saveList(GeneralList<Route>* listRoute)
{
	ofstream file;
	file.open(name);
	file << endl;
	if (file.is_open()) {
		DoubleNode<Route>* currentNodeRoute = listRoute->getHead();
		while (currentNodeRoute) {
			file << "{" << endl;
			file << serializeRoute(currentNodeRoute->getData())<<endl;
			file << "}" << endl;
			currentNodeRoute = currentNodeRoute->getNext();
		}
	}
	file.close();
}

string FileManager::serializeRoute(Route* route)
{
	string data = " ";
	data = "Name: " + route->getName();
	data +="\nColor: "+ serializeColor(route->getColor());
	data += "\n" + serializeListPoint(route->getPointsList());
	return data;
}

string FileManager::serializeColor(Color color)
{
	string data = " ";
	int aux = 0;
	aux = static_cast<int>(color.r);
	data = to_string(aux)+";";
	aux = static_cast<int>(color.g);
	data += to_string(aux) + ";";
	aux = static_cast<int>(color.b);
	data += to_string(aux) + ";";
	aux = static_cast<int>(color.a);
	data += to_string(aux) + ";";
	return data;
}

string FileManager::serializeListPoint(GeneralList<Point>* listPoint)
{
	int aux = 0;
	string data = "";
	DoubleNode<Point>* currentNode = listPoint->getHead();
	while (currentNode) {
		aux = currentNode->getData()->getPositionX();
		data += to_string(aux) +":";
		aux = currentNode->getData()->getPositionY();
		data += to_string(aux) + ";";
		currentNode = currentNode->getNext();
	}
	return data;
}

GeneralList<Route>* FileManager::saveList()
{
	GeneralList<Route>* listRoute = new GeneralList<Route>;
	ifstream file;
	file.open(name);
	string linea;
	while (getline(file, linea)) {
		

		cout << linea << endl;
	}

	file.close();

	return listRoute;
}