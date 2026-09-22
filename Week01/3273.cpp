#include <bits/stdc++.h>
using namespace std;

int a[100005];
bool chk[2000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (x - a[i] > 0 && chk[x - a[i]]) {
            ans++;
        }

        chk[a[i]] = true;
    }

    cout << ans;

    return 0;
}