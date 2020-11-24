#include <iostream>
#include <algorithm>
using namespace std;

int cache[1010][1001];
int getResult(int n, int r);

int main() {
  int r;
  
  fill(&cache[0][0], &cache[1009][1001], -1);
  scanf("%d", &r);
  
  printf("%d \n", getResult(9 + r, r));
  
  return 0;
}

int getResult(int n, int r) {
  int &ret = cache[n][r];
  
  if (ret != -1) return ret;
  
  if (n == r || r == 0) return 1;
  
  return ret = (getResult(n - 1, r - 1) + getResult(n - 1, r)) % 10007;
}