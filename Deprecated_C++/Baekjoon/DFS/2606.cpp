#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> graph[], int start, vector<int> &visited, int &result);

int main() {
  int n, m, a, b, result = 0;
  
  scanf("%d %d", &n, &m);
  
  vector<int> vec[n + 1], visited(n + 1, 0);
  
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  
  for (int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
  
  dfs(vec, 1, visited, result);
  
  printf("%d \n", result - 1);
  
  return 0;
}

void dfs(vector<int> graph[], int start, vector<int> &visited, int &result) {
  visited[start] = 1;
  result++;
  
  for (int i = 0; i < graph[start].size(); i++) {
    if (!visited[graph[start][i]]) dfs(graph, graph[start][i], visited, result);
  }
  
  return;
} 