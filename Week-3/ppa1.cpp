#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> s(n);
        int mn = 1e9;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            mx = max(s[i], mx);
            mn = min(s[i], mn);
        }
        unordered_map<int, int> f1, f2;
        for(int i = 0; i < n; i++) {
            f1[s[i]] = n;
            f2[s[i]] = -1;
        }
        for(int i = 0; i < n; i++) {
            f1[s[i]] = min(f1[s[i]], i + 1);
            f2[s[i]] = max(f2[s[i]], i + 1);
        }
        int ans = 0;
        for(int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            if(f1[x] > 0 && f2[y] > 0 && f1[x] <= f2[y]) {
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}