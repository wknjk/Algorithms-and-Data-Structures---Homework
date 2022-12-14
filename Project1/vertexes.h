#ifndef VERTEXES_H
#define VERTEXES_H
#include "map.h"
class Vertexes {
public:
	Vertexes();
	~Vertexes();
	void addVertex();
	pair<int, int> removeVertex1(int removable_vertex); // dosta posla
	void removeVertex2(int pos, int count);
	void removeVertex3(int removable_index);
	void addEdge(int pos1); 
	int getStartingEdge(int first);
	void removeEdge(int pos1);
	void printVertexes();
private:
	int n; 
	int* vertexes; 
};
#endif // !VERTEXES_H