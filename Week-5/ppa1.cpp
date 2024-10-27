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
        vector<int> p(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        function<int(int)> dfs = [&](int u) -> int {
            if(p[u] == -1) return 1;
            return 1 + dfs(p[u]);
        };
        int mx = 1;
        for(int u = 1; u <= n; u++) {
            mx = max(mx, dfs(u));
        }
        cout << mx << "\n";
    }
    return 0;
}