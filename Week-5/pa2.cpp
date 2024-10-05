#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        function<void(int, int)> dfs = [&](int i, int j) {
            if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
                return;
            }
            grid[i][j] = 0;
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    dfs(ni, nj);
                }
            }
        };
        int groups = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j);
                    groups += 1;
                }
            }
        }
        cout << groups << "\n";
    }
    return 0;
}
