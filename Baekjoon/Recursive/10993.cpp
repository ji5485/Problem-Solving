#include <iostream>
#include <cmath>
using namespace std;

int map[2500][2500] = { 0 };
void printTriangle(int n, int y, int x);
void printStar(int n, int y, int x);

int main() {
  int n;
  
  scanf("%d", &n);
  
  int width = n == 1 ? 1 : (int) pow(2, n + 1) - 3;
  
  if (n == 1) {
    printf("*\n");
  } else {
    printStar(n, n % 2 == 0 ? width / 2 : 0, n == 1 ? 0 : width / 2);
  
    for (int i = 0; i <= width / 2; i++) {
      if (n % 2 == 0) {
          for (int j = 0; j < width - i; j++) printf("%c", map[i][j] ? '*' : ' ');
      } else {
          for (int j = 0; j <= width / 2 + i; j++) printf("%c", map[i][j] ? '*' : ' ');
      }
      printf("\n");
    }
  }
  
  return 0;
}

void printTriangle(int n, int y, int x) {
  int width = (int) pow(2, n + 1) - 3;
  
  for (int i = 0; i <= width / 2; i++) {
    if (n % 2 == 0) map[y - width / 2][x - i] = map[y - width / 2][x + i] = map[y - i][x - i] = map[y - i][x + i] = 1;
    else map[y + width / 2][x - i] = map[y + width / 2][x + i] = map[y + i][x - i] = map[y + i][x + i] = 1;
  }
  
  return;
}

void printStar(int n, int y, int x) {
  if (n == 1) {
    map[y][x] = 1;
    return;
  }
  
  printTriangle(n, y, x);
  
  int width = (int) pow(2, n + 1) - 3;
  int nextY = y + (int) pow(-1, n - 1) * (width / 2 - 1);
  
  printStar(n - 1, nextY, x);
}