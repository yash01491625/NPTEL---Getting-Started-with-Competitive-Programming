#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> sz(N);
vector<int> parent(N, -1);
void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]); 
}
void join(int u, int v) { 
    int x = find(u);
    int y = find(v);
    if (x != y) {
        if (sz[x] < sz[y]) { 
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mp(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mp[i][j];
                if(mp[i][j] == 1) {
                    int idx = i * m + j;
                    make(idx);
                }
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mp[i][j] == 1) {
                    int curr = i * m + j;
                    for(int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && mp[ni][nj] == 1) {
                            int prev = ni * m + nj;
                            join(curr, prev);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mp[i][j] == 1) {
                    int r = find(i * m + j);
                    ans = max(ans, sz[r]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}