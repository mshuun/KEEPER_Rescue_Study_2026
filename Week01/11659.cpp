#include <bits/stdc++.h>
using namespace std;

int s[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        cout << s[b] - s[a - 1] << '\n';
    }

    return 0;
}