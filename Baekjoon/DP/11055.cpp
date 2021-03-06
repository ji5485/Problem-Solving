#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int index);
int cache[1001], val[1001] = { 0 }, n;

int main() {
  scanf("%d", &n);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  for (int i = 1; i <= n; i++)
    scanf("%d", &val[i]);
  
  printf("%d \n", getResult(0));
  
  return 0;
}

int getResult(int index) {
  int &ret = cache[index];
  if (ret != -1) return ret;
  
  if (index >= n + 1) return 0;

  ret = val[index];
  for (int i = index + 1; i <= n; i++) {
    if (val[index] < val[i]) ret = max(ret, val[index] + getResult(i));
  }
  
  return ret;
}