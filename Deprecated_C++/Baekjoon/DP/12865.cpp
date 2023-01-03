#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getResult(int index, int weight);
int cache[101][100001], stuff[2][100], n, k;

int main() {
  scanf("%d %d", &n, &k);
  fill(&cache[0][0], &cache[100][100001], -1);
  
  for (int i = 0; i < n; i++)
    scanf("%d %d", &stuff[0][i], &stuff[1][i]);
  
  printf("%d \n", getResult(0, 0));
  
  return 0;
}

int getResult(int index, int weight) {
  if (weight > k) return numeric_limits<int>::min();
  if (index == n) return 0;
  
  int &ret = cache[index][weight];
  if (ret != -1) return ret;
  
  return ret = max(stuff[1][index] + getResult(index + 1, weight + stuff[0][index]), getResult(index + 1, weight));
}