#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int sum, int prev);
int cache[10001][101], val[100], n, k;

int main() {
  int k;
  
  scanf("%d %d", &n, &k);
  fill(&cache[0][0], &cache[10000][101], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);
  
  int result = getResult(k, 0);
  printf("%d \n", result >= 10000000 ? -1 : result);
  
  return 0;
}

int getResult(int sum, int prev) {
  if (sum == 0) return 0;
  else if (sum < 0) return 10000000;
  
  int &ret = cache[sum][prev];
  if (ret != -1) return ret;
  
  ret = numeric_limits<int>::max();
  for (int i = prev; i < n; i++)
    ret = min(ret, 1 + getResult(sum - val[i], i));
  
  return ret;
}