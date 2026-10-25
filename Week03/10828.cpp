#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;

            st.push(x);
        } else if (op == "pop") {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if (op == "size") {
            cout << st.size() << '\n';
        } else if (op == "empty") {
            cout << st.empty() << '\n';
        } else {
            cout << (st.empty() ? -1 : st.top()) << '\n';
        }
    }

    return 0;
}
