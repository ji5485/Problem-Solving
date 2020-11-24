#include <iostream>
#include <algorithm>
using namespace std;

int cache[31][31];
int getResult(int n, int r);

int main() {
  int t, n, r;
  
  fill(&cache[0][0], &cache[30][31], -1);
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &r, &n);
    printf("%d \n", getResult(n, r));
  }
  
  return 0;
}

int getResult(int n, int r) {
  int &ret = cache[n][r];
  
  if (ret != -1) return ret;
  
  if (n == r || r == 0) return 1;
  
  return ret = getResult(n - 1, r - 1) + getResult(n - 1, r);
}