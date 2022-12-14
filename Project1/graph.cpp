#include "graph.h"
#include <queue>
using namespace std;
struct Node {
	int vertex_index;
	double distance_from;
	int came_here_by;

};


Graph::Graph()
{
	vertexes= new Vertexes();
	edges = new Edges();
	map = new Map();
}

Graph::~Graph()
{
	delete vertexes;
	delete edges;
	delete map;
}

void Graph::addEdge(string first, string second, double distance)
{
	int pos_first = map->getIndex(first);
	int pos_second = map->getIndex(second);

	vertexes->addEdge(pos_first);

	int position = vertexes->getStartingEdge(pos_first);
	edges->addEdge(position, pos_second, distance);
}

void Graph::removeEdge(string first, string second, double distance)
{
	int pos1 = map->getIndex(first);
	int pos2 = map->getIndex(second);
	vertexes->removeEdge(pos1);
	int starting_pos1 = vertexes->getStartingEdge(pos1);
	
	edges->removeEdge(starting_pos1, pos2);

}

void Graph::addVertex(string name)
{
	map->addVertex(name);
	vertexes->addVertex();
}

void Graph::removeVertex(string name)
{
	int index = map->getIndex(name);
	//skidanje grana koje izlaze iz njega
	pair<int, int> positions = vertexes->removeVertex1(index);
	edges->removeVertex1(positions);
	vertexes->removeVertex2(positions.first, (positions.second - positions.first));
	//skidanje grana koje ulaze u njega
	int pos = edges->removeVertex2(index);
	while (pos != -1) {
		vertexes->removeVertex2(pos, 1);
		pos = edges->removeVertex2(index);
	}
	//brisanje tog cvora
	
	vertexes->removeVertex3(index);
	edges->removeVertex3(index);
}



void Graph::printGraph()
{
	map->printMap();
	vertexes->printVertexes();
	edges->printEdges();
}

void Graph::dijkstra_k()
{
	priority_queue<Node> pq;
	int first = 0;
	Node node;
	node.came_here_by = first;
	node.distance_from = 0;
	node.vertex_index = 0;
	pq.push(node);

	while (!pq.empty()) {
		Node current = pq.top();
		pq.pop();

	}
}