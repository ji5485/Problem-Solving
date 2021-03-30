#include <iostream>
#include <algorithm>
using namespace std;

int n, map[500][500], dp[500][500], nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int dfs(int y, int x);

int main() {
  int result = 0;
  
  scanf("%d", &n);
  fill(&dp[0][0], &dp[n - 1][n], -1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  }
    
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)      
      result = max(result, dfs(i, j));
  }
  
  printf("%d \n", result);
  
  return 0;
}

int dfs(int y, int x) {
  int &ret = dp[y][x];
  if (ret != -1) return ret;
  
  ret = 1;
  
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n && map[y][x] < map[nextY][nextX])
      ret = max(ret, 1 + dfs(nextY, nextX));
  }
  
  return ret;
}