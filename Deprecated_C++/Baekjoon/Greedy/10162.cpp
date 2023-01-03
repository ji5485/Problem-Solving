#include <iostream>
using namespace std;

int main() {
  int time, index = 0;
  int btn[3] = { 300, 60, 10 }, clicked[3] = { 0, 0, 0 };
  
  scanf("%d", &time);
  
  while (index <= 2) {
    if (index == 2 && time % btn[index] != 0) break;
    
    clicked[index] = time / btn[index];
    time %= btn[index];
    index++;
  }
  
  if (time != 0) printf("-1 \n");
  else printf("%d %d %d \n", clicked[0], clicked[1], clicked[2]);
  
  return 0;
}