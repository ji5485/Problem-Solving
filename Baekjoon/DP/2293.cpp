#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int sum, int index);
int cache[10000][100], val[100], n, k;

int main() {
  scanf("%d %d", &n, &k);
  fill(&cache[0][0], &cache[9999][100], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);
  
  printf("%d \n", getResult(0, 0));
  
  return 0;
}

int getResult(int sum, int index) {
  if (sum > k || index == n) return 0;
  else if (sum == k) return 1;
  
  int &ret = cache[sum][index];
  if (ret != -1) return ret;
  
  return ret = getResult(sum + val[index], index) + getResult(sum + val[index], index + 1) + getResult(sum, index + 1);
}