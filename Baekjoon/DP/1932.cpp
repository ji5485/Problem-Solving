#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int y, int x, int n);
int cache[500][500], value[500][500] = { 0 };

int main() {
  int n;
  
  fill(&cache[0][0], &cache[499][500], -1);
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      scanf("%d", &value[i][j]);
  }
  
  printf("%d \n", getResult(0, 0, n));
  
  return 0;
}

int getResult(int y, int x, int n) {
  int &ret = cache[y][x];
  
  if (ret != -1) return ret;
  
  if (y == n - 1) return ret = value[y][x];
  
  return ret = value[y][x] + max(getResult(y + 1, x, n), getResult(y + 1, x + 1, n));
}