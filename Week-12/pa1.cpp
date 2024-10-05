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
        vector<vector<long long>> canvas1(n, vector<long long>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> canvas1[i][j];
            }
        }
        vector<vector<long long>> canvas2(n, vector<long long>(m, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> canvas2[j][i];   
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<int>> dp1(n, vector<int>(m, -1));
        vector<vector<int>> dp2(n, vector<int>(m, -1));
        function<int(int, int, vector<vector<int>>&, vector<vector<long long>>&)> solve = [&](int i, int j, vector<vector<int>>& dp, vector<vector<long long>>& canvas) -> int {
            if(i < 0 || i >= n || j < 0 || j >= m) return 0;
            if(dp[i][j] != -1) return dp[i][j]; 
            dp[i][j] = 1;
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && canvas[ni][nj] > canvas[i][j]) {
                    dp[i][j] = max(dp[i][j], 1 + solve(ni, nj, dp, canvas));
                }
            }
            return dp[i][j];
        };
        int ans1 = -1, ans2 = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans1 = max(ans1, solve(i, j, dp1, canvas1));
                ans2 = max(ans2, solve(i, j, dp2, canvas2));
            }
        }
        if(ans1 == ans2) {
            cout << "0\n";
        } else if(ans1 > ans2) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}