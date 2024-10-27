#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
vector<long long> sz(N);
vector<int> parent(N, -1);

void make(int v, int e) {
    parent[v] = v;
    sz[v] = e;
}

int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void join(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x != y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        reverse(b.begin(), b.end());
        vector<bool> in(n, false);
        vector<long long> ans;
        long long mx = 0;
        for (int i = 0; i < n - 1; i++) {
            ans.push_back(mx);
            make(b[i], a[b[i]]);
            in[b[i]] = true;
            if (b[i] < n - 1 && in[b[i] + 1]) {
                join(b[i], b[i] + 1);
            }
            if (b[i] >= 1 && in[b[i] - 1]) {
                join(b[i], b[i] - 1);
            }
            mx = max(mx, sz[find(b[i])]);
        }
        ans.push_back(mx);
        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}