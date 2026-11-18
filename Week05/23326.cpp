#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    set<int> s;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (x) {
            s.insert(i);
        }
    }

    int pos = 1;

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;

            if (s.count(x)) {
                s.erase(x);
            } else {
                s.insert(x);
            }
        } else if (op == 2) {
            long long x;
            cin >> x;

            pos = (pos + x - 1) % n + 1;
        } else {
            if (s.empty()) {
                cout << -1 << '\n';
                continue;
            }

            auto it = s.lower_bound(pos);

            if (it == s.end()) {
                cout << n - pos + *s.begin() << '\n';
            } else {
                cout << *it - pos << '\n';
            }
        }
    }

    return 0;
}
