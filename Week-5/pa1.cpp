#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, a;
        cin >> n >> a;
        vector<int> edges[n + 1];
        for(int i = 0; i < a; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            sort(edges[i].begin(), edges[i].end());
        }
        queue<int> q;
        q.push(1);
        vector<int> parent(n + 1, -1);
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            if(v == n) {
                break;
            }
            for(int u : edges[v]) {
                if(!visited[u]) {
                    visited[u] = true;
                    parent[u] = v;
                    q.push(u);
                }
            }
        }
        if(parent[n] == -1 && n != 1) {
            cout << -1 << "\n";
            continue;
        } else {
            vector<int> path;
            int y = n;
            while(y != -1) {
                path.push_back(y);
                y = parent[y];
            }
            reverse(path.begin(), path.end());
            for(int i = 0; i < (int)path.size(); i++) {
                cout << path[i] << " \n"[i == (int)path.size() - 1];
            }
        }
    }
    return 0;
}
