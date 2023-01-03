#include <iostream>
#include <algorithm>
using namespace std;

long long getResult(int index);
long long cache[91];

int main() {  
  int n;
  
  fill(&cache[0], &cache[91], -1);
  scanf("%d", &n);
  
  cout << getResult(n) << endl;
  
  return 0;
}

long long getResult(int index) {
  long long &ret = cache[index];
  
  if (ret != -1) return ret;
  
  if (index == 0) return ret = 0;
  else if (index == 1) return ret = 1;
  
  return ret = getResult(index - 1) + getResult(index - 2);
}