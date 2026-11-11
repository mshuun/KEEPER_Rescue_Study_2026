#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == e) {
                break;
            }

            for (auto y : a[x]) {
                if (dist[y.first] != -1) {
                    continue;
                }

                dist[y.first] = dist[x] + y.second;
                q.push(y.first);
            }
        }

        cout << dist[e] << '\n';
    }

    return 0;
}
