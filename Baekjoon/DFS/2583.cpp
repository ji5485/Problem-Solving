#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[100][100], m, n;
void dfs(int y, int x, int &val);

int main() {
  int k, x1, y1, x2, y2, val;
  vector<int> result;
  
  scanf("%d %d %d", &m, &n, &k);
  
  for (int i = 0; i < k; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    for (int j = y1; j < y2; j++) {
      for (int l = x1; l < x2; l++)
        map[j][l] = 1;
    }
  }
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j]) continue;
      
      val = 0;
      dfs(i, j, val);
      result.push_back(val);
    }
  }
  
  sort(result.begin(), result.end());
  printf("%d \n", result.size());
  
  for (int i = 0; i < result.size(); i++)
    printf("%d ", result[i]);
  printf("\n");
  
  return 0;
}

void dfs(int y, int x, int &val) {
  map[y][x] = 1;
  val++;
  
  int nextTo[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
  
  for (int i = 0; i < 4; i++) {
    int nextY = y + nextTo[i][0], nextX = x + nextTo[i][1];
    
    if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n && !map[nextY][nextX])
      dfs(nextY, nextX, val);
  }
  
  return;
}