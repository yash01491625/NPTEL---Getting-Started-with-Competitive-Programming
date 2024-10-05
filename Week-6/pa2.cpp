#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        long long n, m, cutoff;
        cin >> n >> m >> cutoff;
        const int INF = 1e9;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    dist[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            dist[u][v] = t;
            dist[v][u] = t;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][j] > (long long)(dist[i][k] + dist[k][j]) && dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        vector<long long> count(n, 0);
        vector<long long> time(n, 0);
        long long mx = -1;
        for(int i = 0; i < n; i++) {
            long long t = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= cutoff) {
                    count[i] += 1;
                    mx = max(mx, count[i]);
                    t += dist[i][j];
                }
            }
            time[i] = t;
        }
        int ans = -1;
        long long mxt = 1e9;
        for(int i = 0; i < n; i++) {
            if(count[i] == mx && mxt >= time[i]) {
                ans = max(ans, i);
                mxt = time[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}