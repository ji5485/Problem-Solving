#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int index);
int cache[1001];

int main() {
  int n;
  
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  scanf("%d", &n);
  
  printf("%d \n", getResult(n));
  
  return 0;
}

int getResult(int index) {
  int &ret = cache[index];
  
  if (ret != -1) return ret;
  
  if (index <= 1) return ret = 1;
  
  return ret = (getResult(index - 1) + 2 * getResult(index - 2)) % 10007;
}