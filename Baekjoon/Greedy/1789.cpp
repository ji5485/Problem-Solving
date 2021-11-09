#include <iostream>
using namespace std;

int main() {
  unsigned long long int n, cnt = 1;
  
  scanf("%llu", &n);
  
  while (n >= cnt * (cnt + 1) / 2) cnt++;
  
  printf("%llu \n", cnt - 1);
  
  return 0;
}
