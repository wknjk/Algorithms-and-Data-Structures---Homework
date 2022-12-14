#include "vertexes.h"
#include <iostream>
using namespace std;
Vertexes::Vertexes()
{
	n = 0;
	vertexes = nullptr;
}
Vertexes::~Vertexes()
{
	delete[] vertexes;
}
void Vertexes::addVertex()
{
	if (vertexes == nullptr) {
		vertexes = new int[2]; vertexes[0] = vertexes[1] = 0;
	}
	else {
		int* helper = new int[n + 2];// da bih cuvala poslednji 'pomocni' clan
		for (int i = 0; i < n + 1; i++)
		{
			helper[i] = vertexes[i];

			// na tu poziciju ce mi ici broj od ovog sto je sledeci i tad ce njegov br edges biti nula
		}
		helper[n + 1] = helper[n];
		delete[] vertexes;
		vertexes = helper;
	}
	n++;
	
}
pair<int, int> Vertexes::removeVertex1(int removable_vertex)
{
	int starting_pos = vertexes[removable_vertex];
	int ending_pos = vertexes[removable_vertex + 1];
	pair<int, int> positions = make_pair(starting_pos, ending_pos);
	return positions;
}
void Vertexes::removeVertex2(int pos, int count)
{
	int i = 0;
	while (vertexes[i] <= pos)
		i++;
	for (i; i < n+1; i++)
		vertexes[i]  = vertexes[i] - count;
	return;
}
void Vertexes::removeVertex3(int removable_index)
{
	int* helper = new int[n];
	for (int i = 0; i < n + 1; i++)
	{
		if (i < removable_index) helper[i] = vertexes[i];
		if (i > removable_index) helper[i - 1] = vertexes[i];
	}
	delete[] vertexes;
	vertexes = helper;
	n--;
}
void Vertexes::printVertexes() {
	cout << "Niz sa cvorovima je: \n";
	for (int i = 0; i < n+1; i++)
		cout << vertexes[i] << " ";
	return;
}

void Vertexes::addEdge(int pos1)
{
	for (int i = pos1 + 1; i < n+1; i++)
		vertexes[i] ++;
}

int Vertexes::getStartingEdge(int first)
{
	return vertexes[first];
}

void Vertexes::removeEdge(int pos1)
{
	for (int i = pos1 + 1; i < n+1; i++)
		vertexes[i] --;
}
