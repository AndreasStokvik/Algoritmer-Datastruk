#pragma once
#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include "vector"
#include "GraphNode.h"

class Graph
{
public:
	Graph();

	void InsertNode(int id);

	void DeleteNode(int value);

private:
	std::vector<GraphNode> nodes;
};

#endif