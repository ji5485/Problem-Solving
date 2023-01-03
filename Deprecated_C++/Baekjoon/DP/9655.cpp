#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int stone, int person);
int cache[1001];

int main() {
  int n;
  
  scanf("%d", &n);
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  int result = getResult(n, 1);
  if (result == 1) printf("%s \n", "SK");
  else if (result == 2) printf("%s \n", "CY");
  
  return 0;
}

int getResult(int stone, int person) {
  if (stone == 0) return 3 - person;
  else if (stone < 0) return 0;
  
  int &ret = cache[stone];
  if (ret != -1) return ret;
  
  return ret = getResult(stone - 1, 3 - person) | getResult(stone - 3, 3 - person);
}