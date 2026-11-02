
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> total, count;

    // 장르별 총 재생 횟수
    for (int i = 0; i < genres.size(); i++)
        total[genres[i]] += plays[i];

    // {장르 총 재생 수, 장르, 노래 재생 수, -고유번호}
    vector<tuple<int, string, int, int>> songs;
    for (int i = 0; i < genres.size(); i++)
        songs.push_back({total[genres[i]], genres[i], plays[i], -i});

    // 재생 횟수 내림차순, 고유번호 오름차순
    sort(songs.rbegin(), songs.rend());

    // 장르별 최대 2곡
    vector<int> answer;
    for (auto &[sum, genre, play, idx] : songs) {
        if (count[genre] < 2) {
            answer.push_back(-idx);
            count[genre]++;
        }
    }

    return answer;
}
