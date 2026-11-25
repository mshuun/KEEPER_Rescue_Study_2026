#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a[20005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        a[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();

        if (d != dist[x]) {
            continue;
        }

        for (auto [y, w] : a[x]) {
            if (d + w < dist[y]) {
                dist[y] = d + w;
                pq.push({dist[y], y});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
