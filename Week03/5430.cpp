#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string p, s;
        int n;
        cin >> p >> n >> s;

        deque<int> dq;
        int pos = 1;

        for (int j = 0; j < n; j++) {
            int x = 0;

            while (s[pos] >= '0' && s[pos] <= '9') {
                x = x * 10 + s[pos] - '0';
                pos++;
            }

            dq.push_back(x);
            pos++;
        }

        bool rev = false;
        bool error = false;

        for (char op : p) {
            if (op == 'R') {
                rev = !rev;
            } else {
                if (dq.empty()) {
                    error = true;
                    break;
                }

                if (rev) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        cout << '[';

        while (!dq.empty()) {
            if (rev) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }

            if (!dq.empty()) {
                cout << ',';
            }
        }

        cout << "]\n";
    }

    return 0;
}
