#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int num, int prev);
int cache[100001];

int main() {
  int num;
  
  scanf("%d", &num);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  printf("%d \n", getResult(num, 1));
  
  return 0;
}

int getResult(int num, int prev) {
  int &ret = cache[num];
  if (ret != -1) return ret;
  
  if (0 <= num && num <= 3) return ret = num;
  else if (num < 0) return 100000;
  
  ret = numeric_limits<int>::max();
  
  for (int i = prev; i <= sqrt(num); i++)
    ret = min(ret, 1 + getResult(num - (int) pow(i, 2), i));
  
  return ret;
}