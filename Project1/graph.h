#ifndef GRAPH_H
#define GRAPH_H
#include "vertexes.h"
#include "map.h"
#include "edges.h"
class Graph {
public:
	Graph();// kako da mi konstruktor Grafa pozove konstruktore drugih klasa?
	~Graph();

	void addEdge(string first, string second, double distance);
	void removeEdge(string first, string second, double distance);
	void addVertex(string name);
	void removeVertex(string name);

	void dijkstra_k();

	void printGraph();
private:
	Vertexes* vertexes;
	Edges* edges;
	Map* map;
	
};


#endif // !GRAPH_H
