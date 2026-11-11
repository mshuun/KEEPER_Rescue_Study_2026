#include <bits/stdc++.h>
using namespace std;

vector<int> a[100005];
int par[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    par[1] = -1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : a[x]) {
            if (par[y]) {
                continue;
            }

            par[y] = x;
            q.push(y);
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << par[i] << '\n';
    }

    return 0;
}
