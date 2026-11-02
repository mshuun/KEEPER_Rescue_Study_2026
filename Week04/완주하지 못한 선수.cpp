#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> people;

    for (const auto &name : participant)
        people[name]++;

    for (const auto &name : completion)
        people[name]--;

    for (const auto &[name, count] : people)
        if (count > 0)
            return name;
}
