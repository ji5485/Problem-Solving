#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int count, int index);
int cache[1001], val[1000], n;

int main() {
  scanf("%d", &n);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);
  
  printf("%d \n", getResult(n, 0));
  
  return 0;
}

int getResult(int count, int index) {
  if (count == 0) return 0;
  else if (count < 0) return numeric_limits<int>::min();
  
  int &ret = cache[count];
  if (ret != -1) return ret;
  
  for (int i = index; i < n; i++)
    ret = max(ret, val[i] + getResult(count - (i + 1), i));
  
  return ret;
}