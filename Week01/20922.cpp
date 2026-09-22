#include <bits/stdc++.h>
using namespace std;

int a[200005];
int cnt[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++) {
        cnt[a[r]]++;

        while (cnt[a[r]] > k) {
            cnt[a[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;

    return 0;
}