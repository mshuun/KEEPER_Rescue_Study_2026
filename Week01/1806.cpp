#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int r = 0; r < n; r++) {
        sum += a[r];

        while (sum >= s) {
            ans = min(ans, r - l + 1);
            sum -= a[l];
            l++;
        }
    }

    if (ans == INT_MAX) {
        cout << 0;
    } else {
        cout << ans;
    }

    return 0;
}