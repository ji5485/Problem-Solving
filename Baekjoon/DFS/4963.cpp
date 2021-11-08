#include <iostream>
#include <algorithm>
using namespace std;

int map[50][50], h, w;

void dfs(int y, int x);

int main() {
  int result;
  
  while(1) {
    scanf("%d %d", &w, &h);
    
    if (w == 0 && h == 0) break;
    
    fill(&map[0][0], &map[49][50], 0);
    result = 0;
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        scanf("%d", &map[i][j]);
    }
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!map[i][j]) continue;
        
        dfs(i, j);
        result++;
      }
    }
    
    printf("%d \n", result);
  }
  
  return 0;
}

void dfs(int y, int x) {
  int nextTo[8][2] = { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1}, { 1, -1} };
  
  map[y][x] = 0;
  
  for (int i = 0; i < 8; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < h && 0 <= nextX && nextX < w && map[nextY][nextX] != 0)
      dfs(nextY, nextX);
  }
  
  return;
}