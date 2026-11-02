#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> pokemons(nums.begin(), nums.end());

    int kinds = pokemons.size();
    int maxPick = nums.size() / 2;

    return min(kinds, maxPick);
}
