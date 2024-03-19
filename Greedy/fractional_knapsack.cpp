// Fractional Knapsack Problem
#include <iostream>
#include <vector>
#include <algorithm>
// #include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        cin >> vp[i].first >> vp[i].second;
    }

    int w;
    cin >> w;

    sort(vp.begin(), vp.end(), [&] (pair<int,int> p1, pair<int,int> p2) {
        double v1 = (double) p1.first/p1.second;
        double v2 = (double) p2.first/p2.second;

        return v1 > v2;
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (w >= vp[i].second) {
            ans += vp[i].first;
            w -= vp[i].second;
        }
        else {
            double vw = (double) vp[i].first/vp[i].second;
            ans += vw * w;
            w = 0;
            break;
        }
    }
    cout << ans << endl;
}