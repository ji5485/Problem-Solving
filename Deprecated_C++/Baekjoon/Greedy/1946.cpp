#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t, n, a, b, result, index;
  vector<pair<int, int>> rank;
  
  scanf("%d", &t);
  
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    
    for (int j = 0; j < n; j++) {
      scanf("%d %d", &a, &b);
      rank.push_back(make_pair(a, b));
    }
    
    sort(rank.begin(), rank.end());
      
    result = 1;
    index = 0;
    for (int j = 1; j < n; j++) {
      if (rank[j].second > rank[index].second) continue;
      
      result++;
      index = j;
    }
    
    printf("%d \n", result);
    rank.clear();
  }
  
  return 0;
}