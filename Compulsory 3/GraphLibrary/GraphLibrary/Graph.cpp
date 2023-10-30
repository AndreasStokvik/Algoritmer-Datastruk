#include "Graph.h"

void Graph::GenerateGraph(int Size)
{
	for (int i = 0; i < Size; i++) {
		GraphNode a;
		a.setValue(i);
		if (i > 1) {
			a.addNeighbors(&a)
		}
	}
}

void Graph::GetNodeInfo()
{
}
