#include <iostream>
#include <algorithm>
using namespace std;

long long getResult(int index);
long long cache[91];

int main() {
  int n;
  
  scanf("%d", &n);
  fill(cache, cache + sizeof(cache) / sizeof(long long), -1);
  
  printf("%lld \n", getResult(n));
  
  return 0;
}

long long getResult(int index) {
  long long &ret = cache[index];
  
  if (ret != -1) return ret;
  
  if (index == 0) return 0;
  else if (index == 1) return 1;
  
  return ret = getResult(index - 1) + getResult(index - 2);
}