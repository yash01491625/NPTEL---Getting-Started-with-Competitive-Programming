#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        vector<vector<long long>> dp(2, vector<long long>(2, 0));    
        const int M = 1e9 + 7;
        for(long long i = n - 1; i >= 0; i--) {
            if(i == n - 1) {
                dp[0][1] += (i % 2 == 1);
                dp[1][1] += (i % 2 == 0);
                dp[0][0] = dp[0][1];
                dp[1][0] = dp[1][1];
            } else {
                if(i % 2 == 0) {            // 1
                    dp[1][0] = 1 + dp[0][1];
                    dp[1][1] = (dp[1][0] + dp[1][1]) % M;
                } else {                    // 0
                    dp[0][0] = 1 + dp[1][1];
                    dp[0][1] = (dp[0][0] + dp[0][1]) % M;
                }
            }
        }
        cout << (dp[0][1] + dp[1][1]) % M << "\n";
    }   
    return 0;
}

/*
1st approach (Last Test Case - runtime error)
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        } else if (n == 2) {
            cout << "3\n";
            continue;
        }
        vector<long long> dp(n);
        dp[0] = 0; 
        dp[1] = 1; 
        const int M = 1e9 + 7;
        for (int i = 2; i < n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;
            dp[i] = (dp[i] + i) % M;
        }
        cout << (dp[n - 1] + n) % M << "\n";
    }   
    return 0;
}
*/
