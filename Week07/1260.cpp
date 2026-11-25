#include <bits/stdc++.h>
using namespace std;

vector<int> a[1005];
bool vis[1005];

void dfs(int x) {
    vis[x] = true;
    cout << x << ' ';

    for (int y : a[x]) {
        if (!vis[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(s);
    cout << '\n';

    fill(vis, vis + n + 1, false);

    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << ' ';

        for (int y : a[x]) {
            if (vis[y]) {
                continue;
            }

            vis[y] = true;
            q.push(y);
        }
    }

    cout << '\n';

    return 0;
}
