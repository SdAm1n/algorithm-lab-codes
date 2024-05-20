#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

// Edge structure for both Kruskal's and Prim's algorithm
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find data structure for Kruskal's algorithm
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Function to use Kruskal's algorithm to find MST
int kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end()); // Sort edges by increasing weight
    UnionFind uf(V);
    int mstCost = 0;
    vector<Edge> mstEdges;

    for (Edge& e : edges) {
        if (uf.find(e.u) != uf.find(e.v)) {
            uf.unite(e.u, e.v);
            mstCost += e.weight;
            mstEdges.push_back(e);
        }
    }

    cout << "Edges in MST (Kruskal's):" << endl;
    for (const Edge& e : mstEdges) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    return mstCost;
}

// Function to use Prim's algorithm to find MST
int primMST(const vector<vector<Edge>>& adj, int V) {
    vector<bool> inMST(V, false);
    vector<Edge> minEdge(V, {-1, -1, INT_MAX});
    minEdge[0].weight = 0; // Start from vertex 0
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({-1, 0, 0});
    int mstCost = 0;

    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mstCost += minEdge[u].weight;

        if (minEdge[u].u != -1) {
            cout << minEdge[u].u << " - " << u << " : " << minEdge[u].weight << endl;
        }

        for (Edge e : adj[u]) {
            if (!inMST[e.v] && e.weight < minEdge[e.v].weight) {
                minEdge[e.v] = {u, e.v, e.weight};
                pq.push({u, e.v, e.weight});
            }
        }
    }
    return mstCost;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges;
    vector<vector<Edge>> adj(V);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w}); // For undirected graph
    }

    int kruskalCost = kruskalMST(edges, V);
    cout << "Total cost of MST (Kruskal's): " << kruskalCost << endl;

    cout << "Edges in MST (Prim's):" << endl;
    int primCost = primMST(adj, V);
    cout << "Total cost of MST (Prim's): " << primCost << endl;

    return 0;
}
