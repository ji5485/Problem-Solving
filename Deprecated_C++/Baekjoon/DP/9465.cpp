#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cache[2][100000], val[2][100000], n;
int getResult(int y, int x);

int main() {
  int t;
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    fill(&cache[0][0], &cache[1][100000], -1);
    
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < n; k++)
        scanf("%d", &val[j][k]);
    }
    
    printf("%d \n", max(getResult(0, 0), getResult(1, 0)));
  }
  
  return 0;
}

int getResult(int y, int x) {
  int &ret = cache[y][x];
  
  if (ret != -1) return ret;
  
  if (x >= n) return numeric_limits<int>::min();
  if (x == n - 1) return ret = val[y][x];
  
  ret = val[y][x];
  return ret = ret + max(getResult((y + 1) % 2, x + 1), getResult((y + 1) % 2, x + 2));
}