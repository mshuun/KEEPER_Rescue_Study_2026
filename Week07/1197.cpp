#include <bits/stdc++.h>
using namespace std;

int par[10005];

int find(int x) {
    if (par[x] < 0) {
        return x;
    }

    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return false;
    }

    if (par[x] > par[y]) {
        swap(x, y);
    }

    par[x] += par[y];
    par[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);

    for (auto &[w, u, v] : edges) {
        cin >> u >> v >> w;
    }

    sort(edges.begin(), edges.end());
    fill(par, par + n + 1, -1);

    int cnt = 0;
    long long ans = 0;

    for (auto [w, u, v] : edges) {
        if (!merge(u, v)) {
            continue;
        }

        ans += w;
        cnt++;

        if (cnt == n - 1) {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
