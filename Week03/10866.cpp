#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> dq;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x;
            cin >> x;

            dq.push_front(x);
        } else if (op == "push_back") {
            int x;
            cin >> x;

            dq.push_back(x);
        } else if (op == "pop_front") {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (op == "pop_back") {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (op == "size") {
            cout << dq.size() << '\n';
        } else if (op == "empty") {
            cout << dq.empty() << '\n';
        } else if (op == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        } else {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }

    return 0;
}
