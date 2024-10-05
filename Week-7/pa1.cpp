#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        int g[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }
        bool vis[n];
        int cost[n];
        for(int i = 0; i < n; i++) {
            vis[i] = false;
            cost[i] = 1e9;
        }
        cost[0] = 0;
        long long sum = 0;
        for(int v = 1; v < n; v++) {
            int u = -1;
            int minCost = 1e9;
            for(int i = 0; i < n; i++) {
                if(!vis[i] && cost[i] < minCost) {
                    u = i;
                    minCost = cost[i];
                }
            }
            vis[u] = true;
            for(int i = 0; i < n; i++) {
                if(vis[i] == false && g[u][i] && cost[i] > g[u][i]) {        
                    cost[i] = g[u][i];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            sum += cost[i];
        }
        cout << x * sum << "\n";
    }
    return 0;
}