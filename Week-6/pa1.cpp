#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> edges[n + 1];
        for(long long i = 0; i < m; i++) {
            long long u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        const long long INF = 1e12;
        vector<long long> dist(n + 1, INF);
        dist[1] = 0;
        vector<long long> parent(n + 1, -1);
        pq.push({0, 1});
        while(!pq.empty()) {
            pair<long long, long long> p = pq.top();
            pq.pop();
            long long w = p.first;
            long long from = p.second;
            if(w > dist[from]) {
                continue;
            }
            for(auto p : edges[from]) {
                long long to = p.first;
                long long w_ = p.second;
                if(dist[from] + w_ < dist[to]) {
                    dist[to] = dist[from] + w_;
                    parent[to] = from;
                    pq.push({dist[to], to});
                }
            }
        }
        cout << dist[n] << "\n";
    }
    return 0;
}