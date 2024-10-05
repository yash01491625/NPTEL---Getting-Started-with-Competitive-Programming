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
        vector<int> h(2 * n);
        for(int i = 0; i < 2 * n; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end());
        bool poss = true;
        for(int i = 0; i < n; i++) {
            if(h[i] > h[i + n] - x) {
                poss = false;
            }
        }
        cout << (poss ? "YES\n" : "NO\n");
    }
    return 0;
}