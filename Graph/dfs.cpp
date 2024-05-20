#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool visited[N];

void dfs(int vertex){

    visited[vertex] = true;
    cout << vertex << endl;
    for (int child: g[vertex]){
        if (!visited[child]) {
            dfs(child);
        }

    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // select the vertex you want to start from
    dfs(2);
}