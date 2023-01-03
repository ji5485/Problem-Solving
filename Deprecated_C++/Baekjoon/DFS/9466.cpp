#include <iostream>
#include <algorithm>
using namespace std;

int n, students[100000], visited[100000];
int dfs(int student, vector<int> &path);

int main() {
  int t, result;
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    fill(&visited[0], &visited[n], 0);
    result = 0;

    for (int j = 0; j < n; j++) {
      scanf("%d", &students[j]);
      students[j] -= 1;
    }
    
    for (int j = 0; j < n; j++) {
      vector<int> path;
      result += dfs(j, path);
    }
    
    printf("%d \n", result);
  }
}

int dfs(int student, vector<int> &path) {
  if (visited[student]) {
    vector<int>::iterator idx = find(path.begin(), path.end(), student);
    return distance(path.begin(), idx);
  }
  
  visited[student] = 1;
  path.push_back(student);
  
  return dfs(students[student], path);
}
