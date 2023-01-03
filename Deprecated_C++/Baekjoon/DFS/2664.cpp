#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<int> graph[], int start, vector<int> &visited, int count, int target);

int main() {
  int n, m, a, b, x, y;
  
  scanf("%d %d %d %d", &n, &a, &b, &m);
  
  vector<int> graph[n + 1], visited(n + 1, 0);
  
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++)
    sort(graph[i].begin(), graph[i].end());
  
  printf("%d \n", dfs(graph, a, visited, 0, b));
  
  return 0;
}

int dfs(vector<int> graph[], int start, vector<int> &visited, int count, int target) {
  if (start == target) return count;
  visited[start] = 1;
  
  for (int i = 0; i < graph[start].size(); i++) {
    if (visited[graph[start][i]]) continue;
    
    int result = dfs(graph, graph[start][i], visited, count + 1, target);
    if (result != -1) return result;
  }
  
  return -1;
}