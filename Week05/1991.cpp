#include <bits/stdc++.h>
using namespace std;

char a[26][2];

void preorder(char x) {
    if (x == '.') {
        return;
    }

    cout << x;
    preorder(a[x - 'A'][0]);
    preorder(a[x - 'A'][1]);
}

void inorder(char x) {
    if (x == '.') {
        return;
    }

    inorder(a[x - 'A'][0]);
    cout << x;
    inorder(a[x - 'A'][1]);
}

void postorder(char x) {
    if (x == '.') {
        return;
    }

    postorder(a[x - 'A'][0]);
    postorder(a[x - 'A'][1]);
    cout << x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char x, l, r;
        cin >> x >> l >> r;

        a[x - 'A'][0] = l;
        a[x - 'A'][1] = r;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}
