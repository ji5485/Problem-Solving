#include <iostream>
#include <algorithm>
using namespace std;

int map[51][51] = { 0 }, n, m;

void dfs(int y, int x);

int main() {
  int t, k, ret, a, b;
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    fill(&map[0][0], &map[50][51], 0);
    ret = 0;
    
    scanf("%d %d %d", &m, &n, &k);
    
    for (int j = 0; j < k; j++) {
      scanf("%d %d", &a, &b);
      map[b][a] = 1;
    }
    
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        if (map[j][l] == 0) continue;
        
        dfs(j, l);
        ret++;
      }
    }
    
    printf("%d \n", ret);
  }
  
  return 0;
}

void dfs(int y, int x) {
  int nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
  
  map[y][x] = 0;
  
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m && map[nextY][nextX] != 0)
      dfs(nextY, nextX);
  }
  
  return;
}