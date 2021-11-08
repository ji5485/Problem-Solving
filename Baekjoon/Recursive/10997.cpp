#include <iostream>
using namespace std;

int map[400][400] = { 0 };
void printBorder(int n, int y, int x);
void printStar(int n, int y, int x);

int main() {
  int n;
  
  scanf("%d", &n);
  
  printStar(n, 0, 0);
  
  for (int i = 0; i < 3 + 4 * (n - 1); i++) {
    for (int j = 0; j < 1 + 4 * (n - 1); j++) {
      if (n != 1 && i == 1 && j >= 1) break;
      printf("%c", (bool) map[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  
  return 0;
}

void printBorder(int n, int y, int x) {
  int width = 1 + 4 * (n - 1), height = 3 + 4 * (n - 1);
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++)
      map[y][x + j] = map[y + height - 1][x + j] = map[y + i][x] = map[y + i][x + width - 1] = 1;
  }
  
  map[y + 1][x + width - 1] = 0;
  map[y + 2][x + width - 2] = 1;
  
  return;
}

void printStar(int n, int y, int x) {
  if (n == 2) {
    printBorder(n, y, x);
    map[y + 2][x + 2] = map[y + 3][x + 2] = map[y + 4][x + 2] = 1;
    return;
  }
  
  if (n == 1) {
    map[y][x] = 1;
    return;
  }
    
  printBorder(n, y, x);
  printStar(n - 1, y + 2, x + 2);
}