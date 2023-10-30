#pragma once

#include "vector"

class GraphNode {
public:
	GraphNode(int value);

	int getValue() const;
	int setValue(int value);
	
	std::vector<GraphNode*>& getNeighbors();
	void addNeighbors(GraphNode* neighbor);

private:
	int value;
	std::vector<GraphNode*> neighbors;
};