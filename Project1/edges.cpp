#include "edges.h"

Edges::Edges()
{
	edges = nullptr;
	m = 0;
}
Edges::~Edges()
{
	delete[] edges;
}
void Edges::removeVertex1(pair<int, int> pos)
{
	int pos1 = pos.first;
	int pos2 = pos.second;
	Edge* helper = new Edge[m - pos2 + pos1];
	for (int i = 0; i < m; i++)
	{
		if (i < pos1) helper[i] = edges[i];
		if (i >= pos2) helper[i-(pos2-pos1)] = edges[i];
	}
	delete[] edges;
	edges = helper;
	m = m - (pos2 - pos1);
	return;

}
int Edges::removeVertex2(int removable_index)
{
	int pos = -1;
	for (int i = 0; i < m; i++) {
		if (edges[i].second_vertex == removable_index) {
			pos = i;
			break;
		}
	}
	if (pos!= -1)
		removeEdge(pos, removable_index);
	return pos;
}
void Edges::removeVertex3(int removable_index)
{
	for (int i = 0; i < m; i++)
		if (edges[i].second_vertex > removable_index) edges[i].second_vertex--;
	return;
}
void Edges::addEdge(int position, int second, double distance)
{
	Edge edge;
	
	edge.second_vertex = second;
	edge.distance = distance;
	Edge* helper = new Edge[m + 1];
	if (m == 0) {
		helper[0] = edge;
	}
	else {
		for (int i = 0; i < m + 1; i++)
		{
			if (i < position) helper[i] = edges[i];
			if (i > position) helper[i] = edges[i - 1];
			if (i == position) helper[i] = edge;
		}
	}
	delete[] edges;
	edges = helper;

	m++;

}
void Edges::printEdges() {
	cout << "lista Edges je:\n";
	for (int i = 0; i < m; i++)
		cout <<"cvor "<< edges[i].second_vertex << " sa duzinom " << edges[i].distance << endl;

}
void Edges::removeEdge(int position, int second)
{
	while (edges[position].second_vertex != second) position++;
	
	Edge* helper = new Edge[m - 1];
	for (int i = 0; i < m; i++) {
		if (i < position) helper[i] = edges[i];
		if (i > position) helper[i - 1] = edges[i];
	}
	delete[] edges;
	edges = helper;
	//smanji broj grana!
	m--;
}