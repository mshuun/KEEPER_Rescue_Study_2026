#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a.insert(a.begin() + i - x - 1, i);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}
