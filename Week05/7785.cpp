#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> s;

    for (int i = 0; i < n; i++) {
        string name, op;
        cin >> name >> op;

        if (op == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }

    vector<string> a(s.begin(), s.end());
    sort(a.rbegin(), a.rend());

    for (const auto &x : a) {
        cout << x << '\n';
    }

    return 0;
}
