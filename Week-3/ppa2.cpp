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
        int am = 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            am = max(am, a[i]);
        }
        int m;
        cin >> m;
        vector<int> b(m);
        int bm = 1;
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            bm = max(bm, b[i]);
        }
        if(am == bm) {
            cout << "Ankita\nBiswas\n";
        } else if(am > bm) {
            cout << "Ankita\nAnkita\n";
        } else {
            cout << "Biswas\nBiswas\n";
        }
    }
    return 0;
}