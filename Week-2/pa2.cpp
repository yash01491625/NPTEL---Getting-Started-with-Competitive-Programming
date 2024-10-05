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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 0;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            if(mx == b[i]) {
                ans += 1;
                mx = -1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}