#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator for the priority queue (min heap)
struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight; // Sort by weight in ascending order
    }
};

// Function to find MST using Prim's algorithm
void primMST(vector<vector<pair<int, int>>>& graph, int startVertex) {
    int n = graph.size(); // Number of vertices
    vector<bool> visited(n, false);
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;

    // Start with the given start vertex
    pq.push({startVertex, startVertex, 0});

    int totalCost = 0;
    while (!pq.empty()) {
        Edge currEdge = pq.top();
        pq.pop();

        int u = currEdge.u;
        int v = currEdge.v;
        int weight = currEdge.weight;

        if (!visited[v]) {
            visited[v] = true;
            totalCost += weight;
            cout << "Edge: " << u << " - " << v << " (Weight: " << weight << ")\n";

            // Add adjacent edges of v to the priority queue
            for (const auto& neighbor : graph[v]) {
                int nextVertex = neighbor.first;
                int edgeWeight = neighbor.second;
                if (!visited[nextVertex]) {
                    pq.push({v, nextVertex, edgeWeight});
                }
            }
        }
    }

    cout << "Total cost of MST: " << totalCost << "\n";
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n); // Adjacency list representation

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int startVertex; // Choose any start vertex
    cin >> startVertex;

    primMST(graph, startVertex);

    return 0;
}
