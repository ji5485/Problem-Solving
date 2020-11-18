#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int getResult(int index, int continuity);
int cache[302][2], score[300], n;

int main() {
  scanf("%d", &n);
  fill(&cache[0][0], &cache[301][2], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &score[i]);
  
  printf("%d \n", getResult(-1, 0));
  
  return 0;
}

int getResult(int index, int continuity) {
  if (index >= n || continuity >= 2) return numeric_limits<int>::min();
  
  int &ret = cache[index + 1][continuity];
  
  if (ret != -1) return ret;
  
  if (index == n - 1) return ret = score[index];

  if (index == -1) ret = max(getResult(0, 0), getResult(1, 0));
  else ret = score[index] + max(getResult(index + 2, 0), getResult(index + 1, continuity + 1));
  
  return ret;
}