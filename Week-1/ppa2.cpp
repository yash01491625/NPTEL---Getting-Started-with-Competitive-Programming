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
        vector<bool> v(n, false);
        v[0] = true;
        int curr = 0;
        for(int i = 1; i <= n; i++) {
            v[(curr + i) % n] = true;
            curr += i;
        }
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(v[i] == false) {
                ok = false;
            }
        }
        cout << (ok ? "Yes\n" : "NO\n");
    }
    return 0;
}
