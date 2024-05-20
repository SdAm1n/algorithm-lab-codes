#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

    cout << "Total cost of MST (Prim's): " << totalCost << "\n";
}

// Function to find parent of a vertex in disjoint set
int findParent(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets
void unionSets(vector<int>& parent, int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

// Function to find MST using Kruskal's algorithm
void kruskalMST(vector<pair<int, pair<int, int>>>& edges, int n) {
    sort(edges.begin(), edges.end()); // Sort edges by weight
    vector<int> parent(n, -1); // Parent array for disjoint set
    vector<pair<int, pair<int, int>>> result; // Resultant MST

    int totalCost = 0;
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;

        int x = findParent(parent, u);
        int y = findParent(parent, v);

        if (x != y) {
            result.push_back({weight, {u, v}});
            totalCost += weight;
            unionSets(parent, x, y);
        }
    }

    cout << "\nKruskal's MST:\n";
    for (auto edge : result) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << "Edge: " << u << " - " << v << " (Weight: " << weight << ")\n";
    }
    cout << "Total cost of MST (Kruskal's): " << totalCost << "\n";
}


int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n); // Adjacency list representation
    vector<pair<int, pair<int, int>>> edges; // Vector of edges for Kruskal's algorithm

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // For undirected graph
        edges.push_back({weight, {u, v}});
    }

    int startVertex; // Choose any start vertex
    cout << "Select Starting Vertex: ";
    cin >> startVertex;

    primMST(graph, startVertex);
    kruskalMST(edges, n);

    return 0;
}
