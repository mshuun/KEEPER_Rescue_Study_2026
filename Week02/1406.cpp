#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    list<char> a(s.begin(), s.end());
    auto cur = a.end();

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;

        if (op == 'L') {
            if (cur != a.begin()) {
                cur--;
            }
        } else if (op == 'D') {
            if (cur != a.end()) {
                cur++;
            }
        } else if (op == 'B') {
            if (cur != a.begin()) {
                cur--;
                cur = a.erase(cur);
            }
        } else {
            char x;
            cin >> x;

            a.insert(cur, x);
        }
    }

    for (char x : a) {
        cout << x;
    }

    return 0;
}
