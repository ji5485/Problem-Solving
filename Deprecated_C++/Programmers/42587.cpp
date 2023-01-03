#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1, val[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    queue<int> priorityQueue;
    
    for (auto priority : priorities) {
        val[priority - 1]++;
        priorityQueue.push(priority);
    }
    
    while (true) {
        int cur = priorityQueue.front();
        bool flag = true;
        
        for (int i = cur; i < 9; i++) {
            if (val[i] > 0) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            val[cur - 1]--;
            priorityQueue.pop();
            
            if (location == 0) break;
            else location--;
            
            answer++;
        } else {
            priorityQueue.pop();
            priorityQueue.push(cur);
            
            if (location == 0) location = priorityQueue.size() - 1;
            else location--;
        }
    }
    
    return answer;
}