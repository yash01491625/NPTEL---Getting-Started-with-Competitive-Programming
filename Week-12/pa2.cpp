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
        string a, b;
        cin >> a >> b;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for(int i = 0; i <= m; i++) {
            dp[0][i] = 1;
        }   
        const int M = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i][j - 1]) % M;
                } else {
                    dp[i][j] = (dp[i][j - 1] + dp[i][j]) % M;
                }
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}