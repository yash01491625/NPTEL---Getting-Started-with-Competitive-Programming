#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long ans = 0;
        long long currSum = 0;
        for(int i = 0; i < n; i++) {
            currSum += v[i];
            ans = max(currSum, ans);
            currSum = max(0LL, currSum);
        }
        cout << x * ans << "\n";
    }
    return 0;
}