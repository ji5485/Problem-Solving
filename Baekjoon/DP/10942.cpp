#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int start, int end);
int cache[2000][2000], arr[2000];

int main() {
  int n, t;
  
  scanf("%d", &n);
  fill(&cache[0][0], &cache[1999][2000], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    printf("%d \n", getResult(start - 1, end - 1));
  }
  
  return 0;
}

int getResult(int start, int end) {
  int &ret = cache[start][end];
  if (ret != -1) return ret;
  
  if (start == end) return ret = 1;
  else if (start + 1 == end) return ret = (arr[start] == arr[end]);
  
  return ret = (arr[start] == arr[end]) && getResult(start + 1, end - 1);
}