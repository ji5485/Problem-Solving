#include <iostream>
#include <algorithm>
using namespace std;

long long getResult(int y, int x);
long long cache[101][101];
int map[100][100], n;

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[100][101], -1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  }
  
  printf("%lld \n", getResult(0, 0));
  
  return 0;
}

long long getResult(int y, int x) {
  if (y == n - 1 && x == n - 1) return 1;
  else if (y >= n || x >= n) return 0;
  
  long long &ret = cache[y][x];
  if (ret != -1) return ret;
  
  if (map[y][x] == 0) return ret = 0;
  
  return ret = getResult(y + map[y][x], x) + getResult(y, x + map[y][x]);
}