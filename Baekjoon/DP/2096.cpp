#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, dp[3][2], tmp[3][3];
  
  scanf("%d", &n);
  
  scanf("%d %d %d", &dp[0][0], &dp[1][0], &dp[2][0]);
  
  dp[0][1] = dp[0][0];
  dp[1][1] = dp[1][0];
  dp[2][1] = dp[2][0];
  
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &tmp[0][0], &tmp[1][0], &tmp[2][0]);
    
    tmp[0][1] = tmp[0][0] + max(dp[0][0], dp[1][0]);
    tmp[1][1] = tmp[1][0] + max({dp[0][0], dp[1][0], dp[2][0]});
    tmp[2][1] = tmp[2][0] + max(dp[1][0], dp[2][0]);
    
    tmp[0][2] = tmp[0][0] + min(dp[0][1], dp[1][1]);
    tmp[1][2] = tmp[1][0] + min({dp[0][1], dp[1][1], dp[2][1]});
    tmp[2][2] = tmp[2][0] + min(dp[1][1], dp[2][1]);
    
    for (int j = 0; j < 3; j++) {
      dp[j][0] = tmp[j][1];
      dp[j][1] = tmp[j][2];
    }
  }
  
  printf("%d %d \n", max({dp[0][0], dp[1][0], dp[2][0]}), min({dp[0][1], dp[1][1], dp[2][1]}));
  
  return 0;
}