#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    int n = gems.size();
    int target = unordered_set<string>(gems.begin(), gems.end()).size();

    unordered_map<string, int> cnt;
    vector<int> answer = {1, n};
    int left = 0;

    for (int right = 0; right < n; right++) {
        cnt[gems[right]]++;

        while (cnt.size() == target) {
            if (right - left < answer[1] - answer[0])
                answer = {left + 1, right + 1};

            if (--cnt[gems[left]] == 0)
                cnt.erase(gems[left]);

            left++;
        }
    }

    return answer;
}
