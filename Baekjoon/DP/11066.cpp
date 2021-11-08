#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int start, int end);
int cache[500][500], file[500];

int main() {
  int t, n;
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    fill(&cache[0][0], &cache[499][500], -1);
    
    for (int j = 0; j < n; j++)
      scanf("%d", &file[j]);
    
    printf("%d \n", getResult(0, n - 1));
  }
  
  return 0;
}

int getResult(int start, int end) {
  int &ret = cache[start][end];
  if (ret != -1) return ret;
  
  if (start == end) return 0;
  
  int sum = 0;
  for (int i = start; i <= end; i++) sum += file[i];
  
  ret = numeric_limits<int>::max();
  for (int i = start; i < end; i++) {
    ret = min(ret, getResult(start, i) + getResult(i + 1, end) + sum);    
  }
  
  return ret;
}