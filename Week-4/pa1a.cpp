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
        int n, b;
        cin >> n >> b;
        for(int i = 1; i <= n; i++) {
            make(i);
        }
        for(int i = 0; i < b; i++) {
            int u, v;
            cin >> u >> v;
            join(u, v);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(find(i) == i) {
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
