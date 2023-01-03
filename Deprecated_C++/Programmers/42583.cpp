#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, index = 0;
    queue<pair<int, int>> bridges;
    
    while (true) {
        if (index == truck_weights.size() && bridges.empty()) break;
      
        if (!bridges.empty() && bridges.front().first == answer - bridge_length) {
            weight += bridges.front().second;
            bridges.pop();
        }
        
        if (index < truck_weights.size() && weight >= truck_weights[index]) {
            weight -= truck_weights[index];
            bridges.push(make_pair(answer, truck_weights[index]));
            index++;
        }
        
        answer++;
    }
    
    return answer;
}

int main() {
  vector<int> vec = { 7, 4, 5, 6 };
  int result = solution(2, 10, vec);
  printf("%d \n", result);
  return 0;
}