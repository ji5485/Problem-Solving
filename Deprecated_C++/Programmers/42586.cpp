#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for (int i = 0; i < progresses.size(); i++) {
        days.push_back((int) ceil((100 - progresses[i]) / (double) speeds[i]));
        printf("%d ", days[i]);
    }
    
    int sum = 1, standard = days[0];
    for (int i = 1; i < days.size(); i++) {
        if (standard < days[i]) {
            answer.push_back(sum);
            sum = 1;
            standard = days[i];
        } else sum++;
    }
    answer.push_back(sum);
    
    return answer;
}

int main() {
  vector<int> progresses = { 90, 80, 95, 97, 75, 85, 90 }, speeds = { 5, 20, 1, 5, 15, 10, 1 };
  
  vector<int> result = solution(progresses, speeds);
  
  printf("\n");
  for (auto it : result)
    printf("%d ", it);
  
  return 0;
}