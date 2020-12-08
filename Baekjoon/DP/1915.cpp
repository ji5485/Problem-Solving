#include <iostream>
#include <cmath>
using namespace std;

int threeMin(int a, int b, int c);
void calcMaxSize();
int arr[1000][1000], n, m;

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%1d", &arr[i][j]);
  }
  
  calcMaxSize();
  
  int maxSize = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      maxSize = max(maxSize, arr[i][j]);
  }
  
  printf("%d \n", maxSize * maxSize);
  
  return 0;
}

int threeMin(int a, int b, int c) {
  return min(a, min(b, c));
}

void calcMaxSize() {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (arr[i][j] != 0) arr[i][j] += threeMin(arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]);
    }
  }
  
  return;
}