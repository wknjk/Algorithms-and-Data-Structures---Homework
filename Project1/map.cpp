#include "map.h"
#include <iostream>
using namespace std;
Map::Map()
{
	n = 0;
	names_of_vertexes = nullptr;
}

Map::~Map()
{
	delete[] names_of_vertexes;
}

void Map::addVertex(string name) {
	string* helper = new string[n+1];
	if (names_of_vertexes == nullptr) 
		 helper[0] = name;
	else {
		for (int i = 0; i < n; i++)
			helper[i] = names_of_vertexes[i];
		helper[n] = name; 
		delete[] names_of_vertexes;
	}
	names_of_vertexes = helper;	
	n++;
}

void Map::removeVertex(string name)
{
	string* helper = new string[n - 1];
	int i=0;
	while (names_of_vertexes[i] != name) {
		helper[i] = names_of_vertexes[i];
		i++;
	}
		

	for (i = i+1; i < n; i++)
		helper[i - 1] = names_of_vertexes[i];
	

	delete[] names_of_vertexes;
	names_of_vertexes = helper;
	n--;
}

int Map::getIndex(string name)
{
	for (int i = 0; i < n; i++)
		if (names_of_vertexes[i] == name) return i;
}

string Map::getName(int i)
{
	return names_of_vertexes[i];
}
void Map::printMap()
{
	cout << "mapa je:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << names_of_vertexes[i] << endl;
	}
}
