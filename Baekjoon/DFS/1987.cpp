#include <iostream>
#include <algorithm>
using namespace std;

char map[20][21];
int r, c, result = 0;
void dfs(int y, int x, int used, int val);

int main() {
  scanf("%d %d", &r, &c);
  
  for (int i = 0; i < r; i++)
    scanf("%s", map[i]);
  
  dfs(0, 0, 0, 0);
  
  printf("%d \n", result);
  
  return 0;
}

void dfs(int y, int x, int used, int val) {
  used = used | (1 << (map[y][x] - 'A'));
  val++;
  
  int nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    int isUsedNextAlpha = used & (1 << (map[nextY][nextX] - 'A'));
    
    if (0 <= nextY && nextY < r && 0 <= nextX && nextX < c && !isUsedNextAlpha)
      dfs(nextY, nextX, used, val);
  }
  
  result = max(result, val);
  
  return;
}