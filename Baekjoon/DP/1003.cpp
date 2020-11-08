#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getResult(int index, int number);
int cache[41][2] = { { 1, 0 }, { 0, 1 } };

int main() {
  int t, tmp;
  
  scanf("%d", &t);
  
  fill(&cache[2][0], &cache[40][2], -1);
  
  for (int i = 0; i < t; i++) {
    scanf("%d", &tmp);
    printf("%d %d \n", getResult(tmp, 0), getResult(tmp, 1));
  }
  
  return 0;
}

int getResult(int index, int number) {
  int &ret = cache[index][number];
  
  if (ret != -1) return ret;
    
  return ret = getResult(index - 1, number) + getResult(index - 2, number);
}