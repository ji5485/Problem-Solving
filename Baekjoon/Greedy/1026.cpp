#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, result = 0;

  scanf("%d", &n);
  
  vector<int> a(n), b(n);
  
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  for (int i = 0; i < n; i++) result += a[i] * b[i];
  
  printf("%d \n", result);
  
  return 0;
}
