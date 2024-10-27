#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int depth, vector<int>& v, vector<int>& d, vector<vector<int>>& e, int& ans, int flip_even, int flip_odd) {
    int val = v[node];
    if (depth % 2 == 0) {
        val ^= flip_even;
    } else {
        val ^= flip_odd;
    }
    if (val != d[node]) {
        ans++;
        if (depth % 2 == 0) {
            flip_even ^= 1;
        } else {
            flip_odd ^= 1;
        }
    }
    for (int child : e[node]) {
        if (child != parent) {
            dfs(child, node, depth + 1, v, d, e, ans, flip_even, flip_odd);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> v(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    int ans = 0;
    dfs(1, -1, 0, v, d, e, ans, 0, 0);
    cout << ans << "\n";
    return 0;
}