#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int index);
int cache[31];

int main() {
  int n;
  scanf("%d", &n);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  printf("%d \n", n % 2 == 0 ? getResult(n) : 0);
  
  return 0;
}

int getResult(int index) {
  if (index < 0) return 0;
  
  int &ret = cache[index];
  if (ret != -1) return ret;
  
  if (index == 0) return 1;
  
  ret = 0;
  for (int i = 2; i <= index; i += 2) {
    if (i == 2) ret += 3 * getResult(index - i);
    else ret += 2 * getResult(index - i);
  }
  
  return ret;
}