#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int getResult(int index, int prevColor);
int cache[1001][3], cost[1000][3], n, result = numeric_limits<int>::max();

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[1000][3], -1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++)
      scanf("%d", &cost[i][j]);
  }
  
  printf("%d \n", getResult(0, -1));
  
  return 0;
}

int getResult(int index, int prevColor) {
  int &ret = prevColor == -1 ? result : cache[index][prevColor];
  
  if (ret != -1 && index != 0) return ret;
  
  if (index == n) return ret = 0;
  
  ret = numeric_limits<int>::max();
    
  for (int i = 0; i < 3; i++) {
    if (i == prevColor) continue;
    ret = min(ret, cost[index][i] + getResult(index + 1, i));
  }
  
  return ret;
}