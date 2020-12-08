#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int index);
int cache[1001], val[1000], n;

int main() {
  scanf("%d", &n);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);
  
  printf("%d \n", getResult(-1) - 1);
  
  return 0;
}

int getResult(int index) {
  int &ret = cache[index + 1];
  
  if (ret != -1) return ret;
  
  ret = 1;
  for (int i = index + 1; i <= n; i++) {
    if (index == -1 || val[index] < val[i]) ret = max(ret, 1 + getResult(i));
  }
  
  return ret;
}