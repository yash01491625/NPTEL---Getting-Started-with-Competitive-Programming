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
        vector<vector<int>> mp(n, vector<int>(n)), wp(n, vector<int>(n)); 
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p;
            for(int j = 0; j < n; j++) {
                cin >> wp[i][j];
                wp[i][j] -= 1;
            } 
        }
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p;
            for(int j = 0; j < n; j++) {
                cin >> mp[i][j];
                mp[i][j] -= 1;
            } 
        }
        vector<bool> ms(n, true), ws(n, true);
        vector<int> midx(n, 0);
        vector<int> q(n);
        iota(q.begin(), q.end(), 0);
        reverse(q.begin(), q.end());
        vector<int> ans(n, -1);
        while (!q.empty()) {
            int m = q.back();
            q.pop_back();
            if (m == -1) {
                break;
            }
            int currIdx = midx[m];
            int w = mp[m][currIdx];
            if (ws[w]) {
                ans[m] = w;
                ms[m] = false;
                ws[w] = false;
                midx[m]++;
            } else {
                int a = -1, pm = -1;
                for (int i = 0; i < n; i++) {
                    if (wp[w][i] == m) a = i;
                    if (ans[i] == w) pm = i;
                }
                if (pm == -1 || a == -1) continue;
                int b = -1;
                for (int i = 0; i < n; i++) {
                    if (wp[w][i] == pm) b = i;
                }
                if (b == -1) continue;
                if (b - a > 0) {
                    ans[pm] = -1;
                    ans[m] = w;
                    ms[pm] = true;
                    q.push_back(pm);
                    ms[m] = false;
                    midx[m]++;
                    midx[pm]++;
                } else {
                    midx[m] += 1;
                    q.push_back(m);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << (i + 1) << " " << (ans[i] + 1) << "\n";
        }
    }
    return 0;
}