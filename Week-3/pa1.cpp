#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        long long n, h;
        cin >> n >> h;
        vector<long long> c(n);
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        sort(c.begin(), c.end());
        cout << (h - (c[0] + c[1]) < 0 ? h : h - (c[0] + c[1])) << "\n";
    }
    return 0;
}