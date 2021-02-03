#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25], n;
void dfs(int y, int x, int &result);

int main() {
  int tmp, result = 0;
  vector<int> val;
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%1d", &map[i][j]);
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!map[i][j]) continue;
      
      result = 0;
      dfs(i, j, result);
      val.push_back(result);
    }
  }
  
  sort(val.begin(), val.end());
  printf("%d \n", val.size());
  
  for (int i = 0; i < val.size(); i++) printf("%d \n", val[i]);
  
  return 0;
}

void dfs(int y, int x, int &result) {
  map[y][x] = 0;
  result++;
  
  int next[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }, nextY, nextX;
  
  for (int i = 0; i < 4; i++) {
    nextY = y + next[i][0];
    nextX = x + next[i][1];
    
    if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
    if (map[nextY][nextX]) dfs(nextY, nextX, result);
  }
  
  return;
}