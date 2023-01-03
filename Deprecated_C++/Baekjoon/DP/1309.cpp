#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int index, int prev);
int cache[100001][2], n;

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[100000][2], -1);
  
  printf("%d \n", getResult(-1, 0));
  
  return 0;
}

int getResult(int index, int prev) {
  if (index == n - 1) return 1;
  
  int &ret = cache[index + 1][prev];
  if (ret != -1) return ret;
  
  if (prev == 0) ret = 2 * getResult(index + 1, 1) + getResult(index + 1, 0);
  else ret = getResult(index + 1, 1) + getResult(index + 1, 0);
  
  return ret % 9901;
}