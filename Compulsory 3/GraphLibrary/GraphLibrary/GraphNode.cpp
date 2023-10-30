#include "GraphNode.h"

GraphNode::GraphNode(int value) : value(value)
{
}

int GraphNode::getValue() const {
	return value;
}

void GraphNode::setValue(int value) {
	this->value = value;
}

std::vector<GraphNode*>& GraphNode::getNeighbors() {
	return neighbors;
}

void GraphNode::addNeighbors(GraphNode* neighbor) {
	neighbors.push_back(neighbor);
}
