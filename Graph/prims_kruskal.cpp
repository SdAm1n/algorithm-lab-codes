#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Comparator for priority queue (Min-Heap)
struct CompareEdge {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};

class Graph {
    int V; // Number of vertices
    vector<Edge> edges; // Edges in the graph

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int xSet = findParent(parent, x);
        int ySet = findParent(parent, y);
        parent[xSet] = ySet;
    }

    void kruskalMST() {
        vector<Edge> result;
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });
        vector<int> parent(V, -1);

        int e = 0, i = 0;
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            int x = findParent(parent, next_edge.src);
            int y = findParent(parent, next_edge.dest);
            if (x != y) {
                result.push_back(next_edge);
                unionSets(parent, x, y);
                e++;
            }
        }

        cout << "Kruskal's MST:\n";
        int totalCost = 0;
        for (auto& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            totalCost += edge.weight;
        }
        cout << "Total cost (Kruskal's): " << totalCost << endl;
    }

    void primMST() {
        priority_queue<Edge, vector<Edge>, CompareEdge> pq;
        int src = 0; // Starting vertex

        // Initial
        vector<bool> inMST(V, false);
        vector<Edge> mst;

        // Insert all edges of starting vertex
        for (Edge& e : edges) {
            if (e.src == src) {
                pq.push(e);
            }
        }
        inMST[src] = true;

        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();

            int target = e.dest;
            // Check if the vertex is already included in MST
            if (inMST[target]) continue;

            mst.push_back(e);
            inMST[target] = true;

            for (Edge& edge : edges) {
                if (edge.src == target && !inMST[edge.dest]) {
                    pq.push(edge);
                }
            }
        }

        cout << "\nPrim's MST:\n";
        int totalCost = 0;
        for (auto& edge : mst) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            totalCost += edge.weight;
        }
        cout << "Total cost (Prim's): " << totalCost << endl;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;

    // Adding edges to the graph
        g.addEdge(e1, e2, w);
    }





    // Finding MST using Kruskal's algorithm
    g.kruskalMST();

    // Finding MST using Prim's algorithm
    g.primMST();

    return 0;
}
