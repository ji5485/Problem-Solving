#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int y, int x, int isGlacier);
int checkNextPosIsGlacier(int isGlacier, int target);
int n, m, map[300][300], visited[300][300], melt[300][300];
int nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int main() {
  int year = 0, result;
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", &map[i][j]);
  }
  
  while (true) {
    fill(&melt[0][0], &melt[n - 1][m], 0);
    
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (map[i][j] == 0) continue;
        
        for (int k = 0; k < 4; k++) {
          int nextY = i + nextTo[k][0], nextX = j + nextTo[k][1];
          if (map[nextY][nextX] == 0) melt[i][j]++;
        }
      }
    }
    
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (melt[i][j] == 0) continue;
        
        map[i][j] -= melt[i][j];
        if (map[i][j] < 0) map[i][j] = 0;
      }
    }
    
    year++;
    result = 0;
    fill(&visited[0][0], &visited[n - 1][m], 0);
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j]) continue;
        
        if (map[i][j] != 0) {
          result++;
          dfs(i, j, 0);
        } else {
          dfs(i, j, 1);
        }
      }
    }
    
    if (result >= 2 || result == 0) break;
  }
  
  printf("%d \n", result == 0 ? 0 : year);
  
  return 0;
}

void dfs(int y, int x, int isGlacier) {
  visited[y][x] = 1;
    
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m && !visited[nextY][nextX] && checkNextPosIsGlacier(isGlacier, map[nextY][nextX]))
      dfs(nextY, nextX, isGlacier);
  }
}

int checkNextPosIsGlacier(int isGlacier, int target) {
  target = target != 0 ? 1 : 0;
  return isGlacier ^ target;
}