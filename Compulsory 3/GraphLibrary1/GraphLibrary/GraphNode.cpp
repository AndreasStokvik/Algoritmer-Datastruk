#include "GraphNode.h"

GraphNode::GraphNode(int value) : NodeValue(value)
{
}

int GraphNode::getValue() const
{
	return NodeValue;
}

void GraphNode::setValue(int value)
{
	this->NodeValue = value;
}

std::vector<GraphNode*>& GraphNode::getNeighbors()
{
	return neighbors;
}

void GraphNode::addNeighbor(GraphNode* neighbor)
{
	neighbors.push_back(neighbor);
}
