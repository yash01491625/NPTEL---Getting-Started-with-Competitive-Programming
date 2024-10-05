#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int h, n;
        cin >> h >> n;
        vector<int> b(n);
        int high = -1;
        int low = 1;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            high = max(high, b[i]);
        } 
        sort(b.begin(), b.end());
        while(low < high) {
            int mid = (low + ((high - low) >> 1));
            int cnt = 0;
            int ans = -1;
            for(int i = 0; i < n; i++) {
                cnt += (mid + b[i] - 1) / mid;
                if(cnt > h) {
                    break;
                }
            }
            if(cnt <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << high << "\n";
    }
    return 0;
}