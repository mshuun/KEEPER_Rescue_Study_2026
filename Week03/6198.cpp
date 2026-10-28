#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (!st.empty() && st.top() <= x) {
            st.pop();
        }

        ans += st.size();
        st.push(x);
    }

    cout << ans;

    return 0;
}
