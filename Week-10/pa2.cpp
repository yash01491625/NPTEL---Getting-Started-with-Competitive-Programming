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
        vector<int> e(n);
        for(int i = 0; i < n; i++) {
            cin >> e[i];
        }
        function<int(int, int, vector<int>&)> solve = [&](int s, int d, vector<int>& dp) -> int {            
            if(s > d) return 0;
            if(dp[s] != -1) return dp[s];
            int nottake = solve(s + 1, d, dp);
            int take = solve(s + 2, d, dp) + e[s];
            return dp[s] = max(nottake, take);
        };
        vector<int> dp(n, -1);
        int ans1 = solve(0, n - 2, dp);
        fill(dp.begin(), dp.end(), -1);
        int ans2 = solve(1, n - 1, dp);
        cout << max(ans1, ans2) << "\n";
    }
    return 0;
}