#include <iostream>

void fillStar(int y, int x, int num);
int map[1024][1024] = { 0 };

int main() {
  int num;
  
  scanf("%d", &num);
  
  fillStar(0, 0, num);
  
  for (int i = 0; i < (1 << num); i++) {
    for (int j = 0; j <= (1 << num) - i - 1; j++)
      printf("%c", map[i][j] ? '*' : ' ');
    printf("\n");
  }
  
  return 0;
}

void fillStar(int y, int x, int num) {
  if (num == 0) {
    map[y][x] = 1;
    return;
  }
  
  fillStar(y, x, num - 1);
  fillStar(y + (1 << (num - 1)), x, num - 1);
  fillStar(y, x + (1 << (num - 1)), num - 1);
  
  return;
}