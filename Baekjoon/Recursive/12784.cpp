#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int getResult(int current, int prev, int country, int map[][1000], int bridges[]);

int main() {
  int t, n, m, cty1, cty2, d;
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &m);
    
    int map[1000][1000] = { 0 };
    int bridges[1000] = { 0 };
    
    for (int j = 0; j < m; j++) {
      scanf("%d %d %d", &cty1, &cty2, &d);
      
      map[cty1 - 1][cty2 - 1] = d;
      bridges[cty1 - 1]++;
      bridges[cty2 - 1]++;
    }
    
    printf("%d \n", getResult(0, -1, n, map, bridges));
  }
  
  return 0;
}

int getResult(int current, int prev, int country, int map[][1000], int bridges[]) {
  int result = numeric_limits<int>::max();
  vector<int> child;
  
  int sum = 0, cnt = 0;
  for (int i = 0; i < country; i++) {
    if ((map[i][current] || map[current][i]) && (i != prev || i == current)) {
      sum += map[i][current] + map[current][i];
      cnt++;
      child.push_back(i);
    }
    
    if (cnt == bridges[current] || (current == 1 && cnt == bridges[current] - 1)) break;
  }
  
  result = min(result, sum);
  
  for (int j = 0; j < child.size(); j++) {
    if (bridges[child[j]] != 1) {
      int tmp = result - (map[child[j]][current] + map[current][child[j]]);
      int childResult = getResult(child[j], current, country, map, bridges);
      result = min(result, tmp + childResult);
    }
  }

  return result;
}