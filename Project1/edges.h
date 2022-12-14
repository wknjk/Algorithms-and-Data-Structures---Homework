#ifndef EDGES_H
#define EDGES_H
#include <iostream>
using namespace std;
class Edges {
public:
	Edges();
	~Edges();
	void removeVertex1(pair<int, int> pos); // dosta posla
	int removeVertex2(int removable_index);
	void removeVertex3(int removable_index);
	void addEdge(int position, int second, double distance);
	void removeEdge(int position, int second);
	void printEdges();
private:
	struct Edge {
		int second_vertex;
		double distance;
	};
	Edge* edges;
	int m;
};

#endif // !EDGES_H
