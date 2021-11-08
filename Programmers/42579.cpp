#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<pair<string, int>> sortMap(map<string, int>& playsByGenres) {
	vector<pair<string, int>> vec;
    
    for (auto& it : playsByGenres)
        vec.push_back(it);
    
    sort(vec.begin(), vec.end(), cmp);
    
    return vec;
}

bool compare_vector(const vector<int>& a, const vector<int>& b) {
	return a[1] > b[1];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> playsByGenres;
    map<string, vector<vector<int>>> orderByGenres;
    
    for (int i = 0; i < genres.size(); i++) {
        map<string, int>::iterator iter = playsByGenres.find(genres[i]);
        map<string, vector<vector<int>>>::iterator ord = orderByGenres.find(genres[i]);
        
        vector<int> newVec = { i, plays[i] };
        
        if (iter == playsByGenres.end()) {
            playsByGenres.insert(make_pair(genres[i], plays[i]));
            orderByGenres.insert(make_pair(genres[i], vector<vector<int>> { newVec }));
        }
        else {
            iter->second += plays[i];
            (ord->second).push_back(newVec);
        }
    }
    
    vector<pair<string, int>> sortedPlays = sortMap(playsByGenres);
    
    for (auto& it : orderByGenres) {
        vector<vector<int>>& vec = it.second;
        sort(vec.begin(), vec.end(), compare_vector);
    }
    
    for (auto& it : sortedPlays) {
        map<string, vector<vector<int>>>::iterator orders = orderByGenres.find(it.first);
        
        int cnt = 0;
        for (auto& ord : (orders->second)) {
          if (cnt >= 2) break;
          answer.push_back(ord[0]);
          cnt++;
        }
    }
    
    return answer;
}