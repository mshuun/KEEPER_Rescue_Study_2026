#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;

            q.push(x);
        } else if (op == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (op == "size") {
            cout << q.size() << '\n';
        } else if (op == "empty") {
            cout << q.empty() << '\n';
        } else if (op == "front") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } else {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }

    return 0;
}
