#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        string path;
        cin >> path;
        vector<int> f(m);
        for(int i = 0; i < n; i++) {
            f[path[i] - '1'] += 1;
        }
        int ans = -1;
        for(int i = 0; i < m; i++) {
            if(f[i] == 2) {
                ans = i + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}