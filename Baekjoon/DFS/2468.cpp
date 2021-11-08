#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, visited[100][100];

void dfs(int y, int x);

int main() {
  int minimum = numeric_limits<int>::max(), maximum = numeric_limits<int>::min(), result = 0;
  
  scanf("%d", &n);
  
  int map[n][n];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &map[i][j]);
      
      minimum = min(minimum, map[i][j]);
      maximum = max(maximum, map[i][j]);
    }
  }
  
  for (int i = minimum - 1; i < maximum; i++) {
    fill(&visited[0][0], &visited[99][100], 1);
    
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (map[j][k] <= i) visited[j][k] = 0;
      }
    }
    
    int val = 0;
    
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (!visited[j][k]) continue;
        
        dfs(j, k);
        val++;
      }
    }
    
    result = max(result, val);
  }
  
  printf("%d \n", result);
  
  return 0;
}

void dfs(int y, int x) {
  int nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
  
  visited[y][x] = 0;
  
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n && visited[nextY][nextX] != 0)
      dfs(nextY, nextX);
  }
  
  return;
}