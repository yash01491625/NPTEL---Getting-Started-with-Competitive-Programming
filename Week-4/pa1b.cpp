#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> edges[], vector<bool>& vis) {
    vis[u] = true;
    for(auto v : edges[u]) {
        if(!vis[v]) {
            dfs(v, edges, vis);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, b;
        cin >> n >> b;
        vector<int> edges[n + 1];
        for(int i = 0; i < b; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<bool> vis(n + 1, false);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                dfs(i, edges, vis);
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
