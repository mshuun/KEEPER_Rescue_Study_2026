#include <bits/stdc++.h>
using namespace std;

vector<int> a[32005];
int indeg[32005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        a[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << ' ';

        for (int y : a[x]) {
            indeg[y]--;

            if (indeg[y] == 0) {
                q.push(y);
            }
        }
    }

    cout << '\n';

    return 0;
}
