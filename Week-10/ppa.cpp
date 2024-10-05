#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        int m; cin >> m;
        vector<int> y(m);
        for(int i = 0; i < m; i++) cin >> y[i];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1] + x[i - 1];
        }
        for(int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + y[i - 1];
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]; 
            }
        }
        int ans = 0;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
