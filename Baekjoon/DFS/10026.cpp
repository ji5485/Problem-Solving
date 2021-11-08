#include <iostream>
#include <algorithm>
using namespace std;

char map[100][101];
int n, visited[100][100] = { 0 };
void dfs(int y, int x, char current);

int main() {
  int result = 0;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++)
    scanf("%s", map[i]);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j]) continue;
      
      dfs(i, j, map[i][j]);
      result++;
    }
  }
  
  printf("%d ", result);
  result = 0;
  fill(&visited[0][0], &visited[99][100], 0);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j]) continue;
      
      dfs(i, j, map[i][j]);
      result++;
    }
  }
  
  printf("%d \n", result);
  
  return 0;
}

void dfs(int y, int x, char current) {
  visited[y][x] = 1;
  if (map[y][x] == 'G') map[y][x] = 'R';
  int nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n && !visited[nextY][nextX] && map[nextY][nextX] == current)
      dfs(nextY, nextX, current);
  }
  
  return;
}