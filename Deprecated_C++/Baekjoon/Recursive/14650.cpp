#include <iostream>
using namespace std;

int getMultipleCount(int n, int index, int sum);

int main() {
  int n;
  
  scanf("%d", &n);
  
  printf("%d \n", getMultipleCount(n, 0, 0));
  
  return 0;
}

int getMultipleCount(int n, int index, int sum) {
  if (n == index) {
    if (sum % 3 == 0) return 1;
    else return 0;
  }
  
  int result = 0;
  
  for (int i = 0; i < 3; i++) {
    if (index == 0 && i == 0) continue;
    result += getMultipleCount(n, index + 1, sum + i);
  }
  
  return result;
}