#pragma once
#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H


#include "vector"

class GraphNode
{
public:
	GraphNode(int value);

	int getValue() const;
	void setValue(int NodeValue);
	
	std::vector<GraphNode*>& getNeighbors();
	void addNeighbor(GraphNode* neighbor);

private:
	int NodeValue;
	std::vector<GraphNode*> neighbors;
};

#endif