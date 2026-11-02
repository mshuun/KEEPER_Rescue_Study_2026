#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> kinds;

    for (const auto &cloth : clothes)
        kinds[cloth[1]]++;

    int result = 1;
    for (const auto &[kind, count] : kinds)
        result *= count + 1;

    return result - 1;
}
