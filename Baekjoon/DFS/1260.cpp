#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector<set<int>> &graph, int start, vector<bool> &visited);
void bfs(vector<set<int>> &graph, int start, vector<bool> &visited);

int main() {
  int n, m, v, a, b;
  
  scanf("%d %d %d", &n, &m, &v);
  
  vector<set<int>> vec(n + 1, set<int>());
  vector<bool> visited(n + 1, false);
  
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    
    vec[a].insert(b);
    vec[b].insert(a);
  }
  
  dfs(vec, v, visited);
  printf("\n");
  fill(visited.begin(), visited.end(), false);
  bfs(vec, v, visited);
  
  return 0;
}

void dfs(vector<set<int>> &graph, int start, vector<bool> &visited) {
  visited[start] = true;
  printf("%d ", start);
  
  for (set<int>::iterator it = graph[start].begin(); it != graph[start].end(); it++) {
    if (!visited[*it]) dfs(graph, *it, visited);
  }
  
  return;
}

void bfs(vector<set<int>> &graph, int start, vector<bool> &visited) {
  queue<int> q;
  
  q.push(start);
  visited[start] = true;
  
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    printf("%d ", tmp);
    
    for (set<int>::iterator it = graph[tmp].begin(); it != graph[tmp].end(); it++) {
      if (visited[*it]) continue;
      
      q.push(*it);
      visited[*it] = true;
    }
  }
  
  return;
}