#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int y, int x);
int moveTo[3][2] = { { 1, 0 }, { 0, 1 }, { 1, 1 } }, cache[1000][1000], cnt[1000][1000], n, m;

int main() {
  scanf("%d %d", &n, &m);
  fill(&cache[0][0], &cache[999][1000], -1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", &cnt[i][j]);
  }
  
  printf("%d \n", getResult(0, 0));
  
  return 0;
}

int getResult(int y, int x) {
  if (y >= n || x >= m) return numeric_limits<int>::min();
  if (y == n - 1 && x == m - 1) return cnt[y][x];
  
  int &ret = cache[y][x];
  if (ret != -1) return ret;
  
  for (int i = 0; i < 3; i++)
    ret = max(ret, cnt[y][x] + getResult(y + moveTo[i][0], x + moveTo[i][1]));
  
  return ret;
}