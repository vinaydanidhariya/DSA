#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
public:
    int V;
    unordered_map<int, vector<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight = 1) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void printGraph() {
        for (const auto& node : adjList) {
            cout << node.first << " -> ";
            for (const auto& neighbor : node.second) {
                cout << neighbor.first << " ";
            }
            cout << endl;
        }
    }

    int dijkstra(int startNode) {
        vector<int> distances(V, INT_MAX);
        unordered_map<int, pair<int, int>> previousNodes;  // Keep track of previous nodes
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distances[startNode] = 0;

        pq.push({0, startNode});

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDistance > distances[currentNode]) continue;

            for (auto neighbor : adjList[currentNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                int distance = currentDistance + weight;
                if (distance < distances[nextNode]) {
                    distances[nextNode] = distance;
                    pq.push({distance, nextNode});
                }
            }
        }

        int shortestDistance = INT_MAX;
        for (int i = 0; i < V; ++i) {
            if (distances[i] != INT_MAX && distances[i] < shortestDistance) {
                shortestDistance = distances[i];
            }
        }

        return shortestDistance;
    }
};

int main() {
    Graph graph;
    graph.V = 5; // Set the number of vertices
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 1);
    graph.addEdge(2, 3, 3);

    // Print the graph
    cout << "Graph:" << endl;
    graph.printGraph();

    // Find shortest distances from a start node
    int startNode = 0;
    int shortestDistance = graph.dijkstra(startNode);

    cout << "\nShortest distance from node " << startNode << ": " << shortestDistance << endl;

    return 0;
}