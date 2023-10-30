#include <iostream>

#include "Graph.h"

using namespace std;

int main()
{
    cout << "asd" << endl;

    //Create 10 nodes
    Graph nodes[10];

    // Assign IDs to each node
    for (int i = 0; i < 10; i++) {
        nodes[i].setValue(i);
    }

    // Add edges between nodes
    nodes[0].addNeighbor(&nodes[1]);
    nodes[0].addNeighbor(&nodes[2]);
    nodes[1].addNeighbor(&nodes[3]);
    nodes[2].addNeighbor(&nodes[4]);
    nodes[3].addNeighbor(&nodes[5]);
    nodes[4].addNeighbor(&nodes[6]);
    nodes[5].addNeighbor(&nodes[7]);
    nodes[6].addNeighbor(&nodes[8]);
    nodes[7].addNeighbor(&nodes[9]);

    return 0;
}