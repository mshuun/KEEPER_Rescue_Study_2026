#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> a) {
    unordered_set<string> book(a.begin(), a.end());

    for (const auto &p : a) {
        for (int i = 0; i < p.size(); i++) {
            if (book.count(p.substr(0, i)))
                return false;
        }
    }
    return true;
}
