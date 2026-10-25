#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            st.pop();

            if (s[i - 1] == '(') {
                ans += st.size();
            } else {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
