#include "FileManager.h"

FileManager::FileManager()
{
	name = "routeFile.mmp";
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
	data += "\nPoint: " + serializeListPoint(route->getPointsList())+ "end;";
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

GeneralList<Route>* FileManager::loadList()
{
	Route* route = new Route();
	GeneralList<Route>* listRoute = new GeneralList<Route>;
	ifstream file;
	file.open(name);
	string line;
	while (getline(file, line)) {
		if (line == "{") {
			route = new Route();
		}
		else if (line == "}") {
			listRoute->insertEnd(route);
		}
		deserailizeNameRoute(line, route);
		deserailizeColor(line, route);
		deserailizeListPoint(line, route);
	}

	file.close();

	return listRoute;
}

void FileManager::deserailizeNameRoute(string line,Route* route)
{
	if (line.find("Name: ") != string::npos) {
		int pos = line.find(":");
		line = line.substr(pos + 1, line.size() - pos - 1);
		route->setName(line);
	}
}

void FileManager::deserailizeColor(string line, Route* route)
{
	int r = 0, g = 0, b = 0, a = 0;
	if (line.find("Color: ") != string::npos) {
		int pos = line.find(":");
		line = line.substr(pos + 1, line.size() - pos - 1);
		pos = line.find(";");
		r = stoi(line.substr(0,pos));
		line = line.substr(pos + 1, line.size() - pos - 1);
		pos = line.find(";");
		g = stoi(line.substr(0, pos));
		line = line.substr(pos + 1, line.size() - pos - 1);
		pos = line.find(";");
		b = stoi(line.substr(0, pos));
		line = line.substr(pos + 1, line.size() - pos - 1);
		pos = line.find(";");
		a = stoi(line.substr(0, pos));
		Color color(r, g, b, a);
		route->setColor(color);
	}
}

void FileManager::deserailizeListPoint(string line, Route* route)
{
	if (line.find("Point: ")!=string::npos) {
		bool hasPoint = true;
		string axuliarLine = "";
		GeneralList<Point>* listPoint = route->getPointsList();
		int position = line.find(":");
		line = line.substr(position + 1, line.size() - position - 1);
		while (hasPoint) {
			position = line.find(";");
			axuliarLine = line.substr(0, position);
			line = line.substr(position + 1, line.size() - position - 1);
			if (axuliarLine == "end") {
				hasPoint=false;
			}
			else {
				insertPoint(axuliarLine, listPoint);
			}
		}
	}
}

void FileManager::insertPoint(string line, GeneralList<Point>* listPoint)
{
	int x = 0, y = 0, pos = 0;
	pos = line.find(":");
	x = stoi(line.substr(0, pos));
	line = line.substr(pos + 1, line.size() - pos - 1);
	y = stoi(line.substr(0, line.size()));
	listPoint->insertEnd(new Point(x, y));
}


