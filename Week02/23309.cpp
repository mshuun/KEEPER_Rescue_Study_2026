#include <bits/stdc++.h>
using namespace std;

int pre[1000005];
int nxt[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        pre[a[i]] = a[(i + n - 1) % n];
        nxt[a[i]] = a[(i + 1) % n];
    }

    for (int i = 0; i < m; i++) {
        string op;
        int x;
        cin >> op >> x;

        if (op == "BN") {
            int y;
            cin >> y;

            int z = nxt[x];
            cout << z << '\n';

            pre[y] = x;
            nxt[y] = z;
            nxt[x] = y;
            pre[z] = y;
        } else if (op == "BP") {
            int y;
            cin >> y;

            int z = pre[x];
            cout << z << '\n';

            pre[y] = z;
            nxt[y] = x;
            nxt[z] = y;
            pre[x] = y;
        } else if (op == "CN") {
            int y = nxt[x];
            cout << y << '\n';

            nxt[x] = nxt[y];
            pre[nxt[y]] = x;
        } else {
            int y = pre[x];
            cout << y << '\n';

            pre[x] = pre[y];
            nxt[pre[y]] = x;
        }
    }

    return 0;
}
