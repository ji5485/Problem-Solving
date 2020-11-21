#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getResult(vector<int> &v);

int main() {
  int n;
  scanf("%d", &n);
  
  vector<int> v(n);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  
  printf("%d \n", getResult(v));
  
  return 0;
}

int getResult(vector<int> &v) {
  int ret = numeric_limits<int>::min(), cache = 0;
  
  for (int i = 0; i < v.size(); i++) {
    cache = max(cache, 0) + v[i];
    ret = max(ret, cache);
  }
  
  return ret;
}