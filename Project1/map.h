#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;
class Map {
public:
	Map();
	~Map();
	void addVertex(string name);
	void removeVertex(string name);
	
	int getIndex(string name);
	string getName(int i);
	
	void printMap();
private:
	string* names_of_vertexes;
	int n;
};


#endif // !MAP_H
