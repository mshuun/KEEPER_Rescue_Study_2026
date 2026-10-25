#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            q.push({j, x});
            pq.push(x);
        }

        int ans = 0;

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            if (x.second == pq.top()) {
                pq.pop();
                ans++;

                if (x.first == m) {
                    cout << ans << '\n';
                    break;
                }
            } else {
                q.push(x);
            }
        }
    }

    return 0;
}
