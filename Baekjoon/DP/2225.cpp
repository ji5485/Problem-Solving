#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int sum, int cnt);
int cache[201][201], MOD = 1000000000;

int main() {
  int n, k;
  
  scanf("%d %d", &n, &k);
  fill(&cache[0][0], &cache[200][201], -1);
  
  printf("%d \n", getResult(n, k));
  
  return 0;
}

int getResult(int n, int k) {  
  if (n == 0 || k == 1) return 1;
  
  int &ret = cache[n][k];
  if (ret != -1) return ret;

  return ret = (getResult(n, k - 1) + getResult(n - 1, k)) % MOD;
}