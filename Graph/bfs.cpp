#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int visited[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int current_vertex = q.front();
        q.pop();
        cout << current_vertex << endl;
        for (int child : g[current_vertex]){
            if (!visited[child]){
                q.push(child);
                visited[child] = 1;

                // to find level
                level[child] = level[current_vertex] + 1;
            }
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

    bfs(0);
}