#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    deque<int> dq[2];
    deque<int> g[2];

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        dq[0].push_back(x);
        dq[1].push_back(y);
    }

    for (int i = 0; i < m; i++) {
        int t = i % 2;
        g[t].push_back(dq[t].back());
        dq[t].pop_back();

        if (dq[t].empty()) {
            cout << (t == 0 ? "su" : "do");
            return 0;
        }

        int w = -1;

        if ((!g[0].empty() && g[0].back() == 5) ||
            (!g[1].empty() && g[1].back() == 5)) {
            w = 0;
        } else if (!g[0].empty() && !g[1].empty() &&
                   g[0].back() + g[1].back() == 5) {
            w = 1;
        }

        if (w != -1) {
            while (!g[1 - w].empty()) {
                dq[w].push_front(g[1 - w].front());
                g[1 - w].pop_front();
            }

            while (!g[w].empty()) {
                dq[w].push_front(g[w].front());
                g[w].pop_front();
            }
        }
    }

    if (dq[0].size() > dq[1].size()) {
        cout << "do";
    } else if (dq[0].size() < dq[1].size()) {
        cout << "su";
    } else {
        cout << "dosu";
    }

    return 0;
}
