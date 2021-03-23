#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001] = { 0 };
int dfs(vector<int> graph[], int start, vector<int> &visited);

int main() {
  int n, x, y;
  
  scanf("%d", &n);
  
  vector<int> graph[n + 1], visited(n + 1, 0);
  
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &x, &y);
    
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++)
    sort(graph[i].begin(), graph[i].end());
  
  dfs(graph, 1, visited);
  
  for (int i = 2; i <= n; i++)
    printf("%d \n", parent[i]);
  
  return 0;
}

int dfs(vector<int> graph[], int start, vector<int> &visited) {
  visited[start] = 1;
  
  for (int i = 0; i < graph[start].size(); i++) {
    if (visited[graph[start][i]]) continue;
    
    parent[graph[start][i]] = start;
    dfs(graph, graph[start][i], visited);
  }
  
  return -1;
}