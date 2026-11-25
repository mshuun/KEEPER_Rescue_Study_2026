#include <bits/stdc++.h>
using namespace std;

vector<int> a[1005];
bool vis[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

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

        ans++;

        queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int y : a[x]) {
                if (vis[y]) {
                    continue;
                }

                vis[y] = true;
                q.push(y);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
