#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int reverse(int index);
int notReverse(int index);
int cache[2][1001], val[1000], n;

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[1][1001], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);
  
  reverse(n);
  notReverse(-1);
  
  int result = 0;
  for (int j = 0; j < n; j++)
    result = max(result, cache[0][j] + cache[1][j + 1] - 1);
  
  printf("%d \n", result);
  
  return 0;
}

int reverse(int index) {
  int &ret = cache[0][index];
  if (ret != -1) return ret;
  
  ret = 1;
  for (int i = index - 1; i >= 0; i--) {
    if (index == n || val[index] > val[i])
      ret = max(ret, 1 + reverse(i));
  }
  
  return ret;
}

int notReverse(int index) {
  int &ret = cache[1][index + 1];
  if (ret != -1) return ret;
  
  ret = 1;
  for (int i = index + 1; i < n; i++) {
    if (index == -1 || val[index] > val[i])
      ret = max(ret, 1 + notReverse(i));
  }
  
  return ret;
}