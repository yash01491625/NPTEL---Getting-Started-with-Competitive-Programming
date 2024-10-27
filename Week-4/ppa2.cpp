#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> sz(N);
vector<int> parent(N, -1);
void make(int v) {
    parent[v] = v;
    sz[v] = 1;
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
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> f(n, false);
        for(int i = 0; i < n; i++) {
            int j = a[i];
            int p = -1;
            while(!f[j]) {
                make(j);
                f[j] = true;
                if(p != -1) {
                    join(j, p);
                }
                p = j;
                j = a[j - 1];
            }
        }
        for(int i = 0; i < n; i++) {
            cout << sz[find(a[i])] << " ";
        }
        cout << "\n";
    }
    return 0;
}