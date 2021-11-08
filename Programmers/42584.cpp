#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        int sec = 0;
        
        for (int j = i + 1; j < prices.size(); j++) {
            sec++;
            if (prices[i] > prices[j]) break;
        }
        
        answer.push_back(sec);
    }
    
    return answer;
}