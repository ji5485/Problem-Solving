#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int index, int continuity);
int cache[10001][3], amount[10000], n;

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[10000][3], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &amount[i]);
  
  printf("%d \n", getResult(-1, 0));
  
  return 0;
}

int getResult(int index, int continuity) {
  if (index >= n || continuity >= 3) return 0;
  
  int &ret = cache[index + 1][continuity];
  if (ret != -1) return ret;
  
  if (index == n - 1) return ret = amount[index];
  
  for (int i = index + 1; i < n; i++)
    ret = max(ret, (index != -1 ? amount[index] : 0) + getResult(i, i == index + 1 ? continuity + 1 : 1));
  
  return ret;
}