#include <iostream>
#include <algorithm>
using namespace std;

long long int getResult(int index, int num);
long long int cache[101][10], MOD = 1000000000;
int n;

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[100][10], -1);
  
  long long int sum = 0;
  for (int i = 1; i <= 9; i++) {
    sum += getResult(1, i);
  }
  
  printf("%lld \n", sum % MOD);
  
  return 0;
}

long long int getResult(int index, int num) {
  long long int &ret = cache[index][num];
  
  if (ret != -1) return ret;
  
  if (index == n) return 1;
  
  ret = 0;
  if (num != 0) ret += getResult(index + 1, num - 1);
  if (num != 9) ret += getResult(index + 1, num + 1);
  ret %= MOD;
  
  return ret;
}