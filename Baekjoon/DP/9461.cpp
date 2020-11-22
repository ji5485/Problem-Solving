#include <iostream>
#include <algorithm>
using namespace std;

long long int getResult(int index);
long long int cache[100] = { 1, 1, 1, 2, 2 };

int main() {
  int t, n;
  
  scanf("%d", &t);
  fill(cache + 5, cache + sizeof(cache) / sizeof(int), -1);
  
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%lld \n", getResult(n - 1));
  }
  
  return 0;
}

long long int getResult(int index) {
  long long int &ret = cache[index];
  
  if (ret != -1) return ret;
  
  return ret = getResult(index - 5) + getResult(index - 1);
}