#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothesMap;
    
    for (vector<vector<string>>::iterator iter = clothes.begin(); iter != clothes.end(); iter++) {
        map<string, int>::iterator clothesIter = clothesMap.find((*iter)[1]);
        
        if (clothesIter == clothesMap.end()) clothesMap.insert(make_pair((*iter)[1], 1));
        else clothesIter->second = clothesIter->second + 1;
    }
    
    for (auto iter = clothesMap.begin(); iter != clothesMap.end(); iter++)
        answer *= iter->second + 1;
    
    answer -= 1;
    
    printf("%d \n", answer);
    
    return answer;
}