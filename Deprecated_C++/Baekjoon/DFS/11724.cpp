#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> graph[], int start, vector<int> &visited);

int main() {
  int n, m, a, b, result = 0;
  
  scanf("%d %d", &n, &m);
  
  vector<int> graph[n + 1], visited(n + 1, 0);
  
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  for (int i = 1; i <= n; i++)
    sort(graph[i].begin(), graph[i].end());
  
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    
    dfs(graph, i, visited);
    result++;
  }
  
  printf("%d \n", result);
  
  return 0;
}

void dfs(vector<int> graph[], int start, vector<int> &visited) {
  visited[start] = 1;
  
  for (int i = 0; i < graph[start].size(); i++) {
    if (!visited[graph[start][i]])
      dfs(graph, graph[start][i], visited);
  }
  
  return;
}