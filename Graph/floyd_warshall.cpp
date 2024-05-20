#include <iostream>
using namespace std;

const int N = 1001;
const int INF = 1e9+10;

int dist[N][N];

int main() {
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        dist[v1][v2] = wt;
        
    }

    for (int k = 1; k <= vertices; k++) {
        for (int i = 1; i <= vertices; i++) {
            for (int j = 1; j <= vertices; j++) {
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            if (dist[i][j] == INF) cout << "I" << " ";
            else {
                cout << dist[i][j] << " ";
            } 
        }
        cout << endl;
    }

}