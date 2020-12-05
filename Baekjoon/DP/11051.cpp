#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int n, int k);
int cache[1001][1001];

int main() {
  int n, k;
  
  scanf("%d %d", &n, &k);
  fill(&cache[0][0], &cache[1000][1001], -1);
  
  printf("%d \n", getResult(n, k));
  
  return 0;
}

int getResult(int n, int k) {
  int &ret = cache[n][k];
  if (ret != -1) return ret;
  
  if (n == 0 || k == 0 || n == k) return ret = 1;
  
  return ret = (getResult(n - 1, k) + getResult(n - 1, k - 1)) % 10007;
}