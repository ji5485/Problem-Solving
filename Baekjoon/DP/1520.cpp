#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int y, int x);
int moveTo[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } }, cache[500][500], cnt[500][500], n, m;

int main() {
  scanf("%d %d", &n, &m);
  fill(&cache[0][0], &cache[499][500], -1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", &cnt[i][j]);
  }
  
  printf("%d \n", getResult(0, 0));
  
  return 0;
}

int getResult(int y, int x) {
  if (y == n - 1 && x == m - 1) return 1;
  
  int &ret = cache[y][x];
  if (ret != -1) return ret;
  
  ret = 0;
  int nextY, nextX;
  for (int i = 0; i < 4; i++) {
    nextY = y + moveTo[i][0];
    nextX = x + moveTo[i][1];
    
    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m && cnt[y][x] > cnt[nextY][nextX])
      ret += getResult(nextY, nextX);
  }
  
  return ret;
}