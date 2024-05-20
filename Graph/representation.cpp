#include <iostream>
#include <vector>
using namespace std;

// For undirected graph

const int N = 1e3 + 10;

// Adjacency Matrix
int graph1[N][N];

// Adjacency List
vector<int> graph2[N];

// for weighted adjacency list
vector<pair<int, int>> graph3[N];

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        // for adjacency matrix
        // for weighted graph replace 1 with the weight
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;

        // for adjacency list O(vertices ^ 2) or O(n^2)
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);

        // for weighted adjacency list O(vertices + edges)
        graph3[v1].push_back({v2, wt});
        graph3[v2].push_back({v1, wt});
    }
}