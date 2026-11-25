#include <bits/stdc++.h>
using namespace std;

bool bfs(int s, const vector<vector<int>> &a, vector<int> &color) {
    queue<int> q;
    q.push(s);
    color[s] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : a[x]) {
            if (color[y] == color[x]) {
                return false;
            }

            if (color[y] == 0) {
                color[y] = -color[x];
                q.push(y);
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n + 1);
        vector<int> color(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            a[u].push_back(v);
            a[v].push_back(u);
        }

        bool ok = true;

        for (int i = 1; i <= n; i++) {
            if (color[i] == 0 && !bfs(i, a, color)) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
