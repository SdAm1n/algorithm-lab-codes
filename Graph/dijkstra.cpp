#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair <int, int>> g[N];
vector<int> dist(N, INF);
int visited[N];

void dijsktra(int source) {
    

    set<pair <int, int >> st;
    st.insert({0, source});

    dist[source] = 0;
    
    while (st.size() > 0) {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if (visited[v]) continue;
        visited[v] = 1;

        for (auto child: g[v]){
            int child_v = child.second;
            int child_wt = child.first;

            if (dist[v] + child_wt < dist[child_v]){
                dist[child_v] = dist[v] + child_wt;
                st.insert({dist[child_v], child_v});
            }
        }
        
    }


}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        g[v1].push_back({wt, v2});
    }

    dijsktra(0);

    cout << "vertices : distances"<< endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << "           "<< dist[i] << endl;
    }
}