#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int t = 0;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<int>> a(n + 1);
        vector<int> vis(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            a[u].push_back(v);
            a[v].push_back(u);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                continue;
            }

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            int nodes = 0;
            int edges = 0;

            while (!q.empty()) {
                int x = q.front();
                q.pop();

                nodes++;
                edges += a[x].size();

                for (int y : a[x]) {
                    if (vis[y]) {
                        continue;
                    }

                    vis[y] = 1;
                    q.push(y);
                }
            }

            if (edges / 2 == nodes - 1) {
                ans++;
            }
        }

        cout << "Case " << ++t << ": ";

        if (ans == 0) {
            cout << "No trees." << '\n';
        } else if (ans == 1) {
            cout << "There is one tree." << '\n';
        } else {
            cout << "A forest of " << ans << " trees." << '\n';
        }
    }

    return 0;
}
