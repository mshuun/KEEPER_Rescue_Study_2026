#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<pair<int, int>> dq;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        dq.push_back({i, x});
    }

    while (!dq.empty()) {
        int x = dq.front().second;
        cout << dq.front().first << ' ';
        dq.pop_front();

        if (dq.empty()) {
            break;
        }

        if (x > 0) {
            for (int i = 0; i < x - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < -x; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
