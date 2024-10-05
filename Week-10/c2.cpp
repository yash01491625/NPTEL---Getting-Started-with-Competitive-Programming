#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> dp(n + 1);
        dp[0] = 1;
        const int mod = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 6; j++) {
                if(i - j >= 0) {
                    dp[i] = (dp[i] + dp[i - j]) % mod;
                }
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}