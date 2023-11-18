#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * @brief Represents a graph and its associated operations.
 */
class Graph {
private:
    unordered_map<int, vector<int>> adjacencyList; ///< Adjacency list representation of the graph.

public:
    /**
     * @brief Adds an edge between two vertices in the graph.
     * @param u The first vertex.
     * @param v The second vertex.
     */
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    /**
     * @brief Prints the adjacency list representation of the graph.
     */
    void printGraph() {
        for (const auto& entry : adjacencyList) {
            cout << entry.first << " -> ";
            for (int vertex : entry.second) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    /**
     * @brief Prints nodes adjacent to the specified node.
     * @param node The target node.
     */
    void printAdjacentNodes(int node) {
        if (adjacencyList.find(node) != adjacencyList.end()) {
            cout << "Adjacent nodes to " << node << ": ";
            for (int adjacentNode : adjacencyList[node]) {
                cout << adjacentNode << " ";
            }
            cout << endl;
        }
        else {
            cout << "Node " << node << " not found in the graph." << endl;
        }
    }

    /**
     * @brief Prints all nodes in the graph exactly once.
     */
    void printAllNodes() {
        unordered_set<int> visited;

        for (const auto& entry : adjacencyList) {
            int node = entry.first;
            if (visited.find(node) == visited.end()) {
                cout << node << " ";
                visited.insert(node);
            }

            for (int vertex : entry.second) {
                if (visited.find(vertex) == visited.end()) {
                    cout << vertex << " ";
                    visited.insert(vertex);
                }
            }
        }

        cout << endl;
    }

    /**
     * @brief Prints the size (number of vertices) of the graph.
     */
    void printSize() {
        cout << "Size of the graph: " << adjacencyList.size() << " vertices" << endl;
    }

    /**
     * @brief Checks if the graph is empty and prints the result.
     */
    void isEmpty() {
        if (adjacencyList.size() < 1) {
            cout << "The graph is empty..." << endl;
        }
        else {
            cout << "The graph is not empty, " << endl;
            printSize();
        }
    }

    /**
     * @brief Inserts a random vertex into the graph and connects it to an existing node.
     */
    void insertRandomVertex() {
        int newVertex = rand() % 100;
        int existingVertex;

        if (adjacencyList.empty()) {
            cout << "Graph is empty. Cannot connect to an existing node.\n";
            return;
        }
        else {
            auto it = adjacencyList.begin();
            advance(it, rand() % adjacencyList.size());
            existingVertex = it->first;
        }

        adjacencyList[newVertex];

        addEdge(newVertex, existingVertex);
    }

    /**
     * @brief Deletes a node from the graph, along with all edges connected to it.
     * @param node The node to be deleted.
     */
    void deleteNode(int node) {
        cout << "Deleting node " << node << endl;
        // removes edges connected to the node
        adjacencyList.erase(node);

        // removes the node from all other adjacency lists
        for (auto& entry : adjacencyList) {
            vector<int>& neighbors = entry.second;
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), node), neighbors.end());
        }
    }

    /**
     * @brief Deletes an edge between two vertices in the graph.
     * @param u The first vertex.
     * @param v The second vertex.
     */
    void deleteEdge(int u, int v) {
        // finds the desired vertices in the adjacency list
        auto it_u = adjacencyList.find(u);
        auto it_v = adjacencyList.find(v);

        if (it_u != adjacencyList.end() && it_v != adjacencyList.end()) {
            // remove v from the adjacency list of u
            it_u->second.erase(remove(it_u->second.begin(), it_u->second.end(), v), it_u->second.end());

            // remove u from the adjacency list of v
            it_v->second.erase(remove(it_v->second.begin(), it_v->second.end(), u), it_v->second.end());
        }
    }

    /**
     * @brief Performs a Depth-First Search traversal from a start vertex to a target vertex.
     * @param startVertex The starting vertex.
     * @param targetVertex The target vertex to reach during the traversal.
     */
    void DFS(int startVertex, int targetVertex) {
        unordered_set<int> visited;
        stack<int> s;
        unordered_map<int, int> parent; // stores the parent of each visited vertex

        s.push(startVertex);
        visited.insert(startVertex);
        parent[startVertex] = -1; // the starting vertex has no parent

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            cout << currentVertex << " ";

            if (currentVertex == targetVertex) {
                cout << "(Target reached)" << endl;

                // print the direct path
                cout << "Direct path from " << startVertex << " to " << targetVertex << ": ";
                int vertex = targetVertex;
                vector<int> path;
                while (vertex != -1) {
                    path.push_back(vertex);
                    vertex = parent[vertex];
                }
                for (int i = path.size() - 1; i >= 0; --i) {
                    cout << path[i] << " ";
                }
                cout << endl;

                return;
            }

            for (int neighbor : adjacencyList[currentVertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
                    visited.insert(neighbor);
                    parent[neighbor] = currentVertex;
                }
            }
        }

        cout << "(Target not reached)" << endl;
    }
};

int main() {
    srand(time(nullptr));

    Graph myGraph;

    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(3, 4);
    myGraph.addEdge(17, 4);

    // Print the graph
    myGraph.printGraph();

    myGraph.insertRandomVertex();
    myGraph.insertRandomVertex();
    myGraph.insertRandomVertex();
    myGraph.insertRandomVertex();

    cout << endl;
    myGraph.printAdjacentNodes(17);

    cout << endl;
    myGraph.printAllNodes();

    cout << endl;
    myGraph.printSize();

    cout << endl;
    myGraph.isEmpty();

    cout << endl;
    cout << "New graph: " << endl;
    myGraph.printGraph();

    cout << endl;
    //myGraph.deleteNode(2);
    //myGraph.deleteEdge(1, 3);
    cout << "New new graph: " << endl;
    myGraph.printGraph();

    cout << endl;
    myGraph.DFS(1, 4);

    return 0;
}
