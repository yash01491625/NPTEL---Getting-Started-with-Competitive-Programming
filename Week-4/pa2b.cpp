#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int dfs(int i, int j, vector<vector<int>>& mp, vector<vector<bool>>& visited) {
    if(i < 0 || j < 0 || i >= mp.size() || j >= mp[0].size() || visited[i][j] == true || mp[i][j] == 0) {
        return 0;
    }
    visited[i][j] = true;
    int size = 1;
    for(int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        size += dfs(ni, nj, mp, visited);
    }
    return size;
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
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int b = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int a = dfs(i, j, mp, visited);
                b = max(a, b);
            }
        }
        cout << b << "\n";
    }
    return 0;
}