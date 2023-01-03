#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class POS {
  public:
    int x;
    int y;

    POS(int x, int y) {
      this->x = x;
      this->y = y;
    }
  
    void swap() {
      int tmp;
      
      tmp = this->x;
      this->x = this->y;
      this->y = tmp;
    }
};

POS getPos(int num, int expo);

int main() {
  int n, m;
  
  scanf("%d %d", &n, &m);
  
  int expo = (int) log2((double) n);
  
  POS result = getPos(m, expo);
  
  printf("%d %d \n", result.x, result.y);
  
  return 0;
}

POS getPos(int num, int expo) {
  if (expo == 1) {
    POS val[4] = { POS(1, 1), POS(1, 2), POS(2, 2), POS(2, 1) };
    return val[num - 1];
  }
  
  int block = 1 << ((expo - 1) * 2);
  int pos = (num - 1) / block;
  int prev = pos * block;
    
  POS result = getPos(num - prev, expo - 1);
  
  switch (pos) {
    case 0:
      result.swap();
      return result;
    case 1:
      result.y += 1 << (expo - 1);
      return result;
    case 2:
      result.x += 1 << (expo - 1);
      result.y += 1 << (expo - 1);
      return result;
    case 3:
      int tmp = result.x;
      result.x = 2 * (1 << (expo - 1)) + 1 - result.y;
      result.y = (1 << (expo - 1)) + 1 - tmp;
      return result;
  }
  
  return result;
}