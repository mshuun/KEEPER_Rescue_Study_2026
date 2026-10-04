#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> dq;

    for (int i = n - 1; i >= 0; i--) {
        int x = n - i;

        if (a[i] == 1) {
            dq.push_front(x);
        } else if (a[i] == 2) {
            int y = dq.front();
            dq.pop_front();
            dq.push_front(x);
            dq.push_front(y);
        } else {
            dq.push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dq[i] << ' ';
    }

    return 0;
}
