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
        vector<int> h(n);
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<int> dp(n);
        for(int i = 1; i < n; i++) {
            int j1 = dp[i - 1] + abs(h[i] - h[i - 1]);
            int j2 = INT_MAX;
            if(i >= 2) {
                j2 = dp[i - 2] + abs(h[i] - h[i - 2]);
            }
            dp[i] = min(j1, j2);
        }
        cout << dp[n - 1] << "\n";
    }
    return 0;
}