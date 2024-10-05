#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges[n + 1];
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
        bool vis[n + 1];
        int cost[n + 1];
        for(int i = 1; i <= n; i++) {
            vis[i] = false;
            cost[i] = 1e9;
        }
        cost[1] = 0;
        for(int count = 1; count < n; count++) {
            int u = -1;
            int minCost = 1e9;
            for(int i = 1; i <= n; i++) {
                if(!vis[i] && cost[i] < minCost) {
                    u = i;
                    minCost = cost[i];
                }
            }
            vis[u] = true;
            for(auto v : edges[u]) {
                int to = v.first;
                int wt = v.second;
                if(!vis[to] && cost[to] > wt) {
                    cost[to] = wt;
                }
            }
        }
        long long sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += cost[i];
        }
        cout << sum << "\n";
    }
    return 0;
}