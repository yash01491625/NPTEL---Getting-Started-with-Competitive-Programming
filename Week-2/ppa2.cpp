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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> p(n + 1);
        for(int i = 0; i < n; i++) {
            p[i + 1] = p[i] + a[i];
        }
        while(q--) {
            int k;
            cin >> k;
            int low = 0;
            int high = n;
            int ans = -1;
            while(low < high) {
                int mid = (low + ((high - low) >> 1));
                if(p[n] - p[mid] >= k) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            cout << (ans == -1 ? ans : n - ans) << "\n";
        }
    }
    return 0;
}