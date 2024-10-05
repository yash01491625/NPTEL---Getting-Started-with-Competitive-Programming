#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, x, s;
        cin >> n >> x >> s;
        string a;
        cin >> a;
        long long ans = 1;
        long long l, r;
        for(long long i = 0; i < n; i++) {
            // Even
            l = i, r = i + 1;
            while(l >= 0 && r < n && a[l] == a[r]) {
                l -= 1;
                r += 1;
            }   
            ans = max(ans, r - l - 1);
            // Odd
            l = i, r = i;
            while(l >= 0 && r < n && a[l] == a[r]) {
                l -= 1;
                r += 1;
            } 
            ans = max(ans, r - l - 1);
        }
        cout << (ans * s >= x ? "1\n" : "0\n");
    }
    return 0;
}