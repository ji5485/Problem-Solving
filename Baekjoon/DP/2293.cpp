#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, k, dp[10001] = { 0 }, val[101];
  
  scanf("%d %d", &n, &k);
  
  for (int i = 1; i <= n; i++)
    scanf("%d", &val[i]);
  
  dp[0] = 1;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (val[i] <= j) dp[j] += dp[j - val[i]];
    }
  }
  
  printf("%d \n", dp[k]);
  
  return 0;
}