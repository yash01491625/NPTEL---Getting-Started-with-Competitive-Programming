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
        bool left = true;
        for(int i = 1; i < n; i++) {
            if(a[i - 1] > a[i]) {
                left = false;
            }
        }
        bool right = true;
        for(int i = 1; i < n; i++) {
            if(a[i - 1] < a[i]) {
                right = false;
            }
        }
        if(left) {
            cout << "L\n";
        } else if(right) {
            cout << "R\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}