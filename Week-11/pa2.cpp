#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>> ways(n, vector<long long>(m, 0));
        for(int i = 0; i < n; i++) {
            ways[i][0] = 1;
        }
        for(int i = 0; i < m; i++) {
            ways[0][i] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
            }
        }
        cout << ways[n - 1][m - 1] << "\n";
    }
    return 0;
}