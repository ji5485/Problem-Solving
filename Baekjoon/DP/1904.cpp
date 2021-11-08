#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int num);
int cache[1000001];

int main() {
  int num;
  
  scanf("%d", &num);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  printf("%d \n", getResult(num));
  
  return 0;
}

int getResult(int num) {
  int &ret = cache[num];
  if (ret != -1) return ret;
  
  if (num == 0 || num == 1) return 1;
  
  return ret = (getResult(num - 1) + getResult(num - 2)) % 15746;
}