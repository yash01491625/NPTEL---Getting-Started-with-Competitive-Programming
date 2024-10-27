#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> e[n + 1];
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        vector<int> sz(2, 0);
        function<void(int, int, int)> dfs = [&](int u, int p, int ok) -> void {
            sz[ok] += 1;
            for(int& v : e[u]) {
                if(v != p) {
                    dfs(v, u, (ok ^ 1));
                }
            }
        };
        dfs(1, -1, 0);
        cout << (sz[0] * 1LL * sz[1]) - n + 1 << "\n";
    }
    return 0;
}