#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        list<char> a;
        auto cur = a.end();

        for (char x : s) {
            if (x == '<') {
                if (cur != a.begin()) {
                    cur--;
                }
            } else if (x == '>') {
                if (cur != a.end()) {
                    cur++;
                }
            } else if (x == '-') {
                if (cur != a.begin()) {
                    cur--;
                    cur = a.erase(cur);
                }
            } else {
                a.insert(cur, x);
            }
        }

        for (char x : a) {
            cout << x;
        }

        cout << '\n';
    }

    return 0;
}
