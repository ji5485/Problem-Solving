#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& pair1, const pair<int, int>& pair2) {
  if (pair1.second == pair2.second) return pair1.first < pair2.first;
  else return pair1.second < pair2.second;
}

int main() {
  int n, result = 0, a, b;
  scanf("%d" ,&n);
  
  vector<pair<int, int>> vec(n);
  
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    vec[i] = make_pair(a, b);
  }
  
  sort(vec.begin(), vec.end(), cmp);
  
  int current = vec[0].second;
  result = 1;
  
  for (int i = 1; i < n;) {
    if (vec[i].first >= current) {
      current = vec[i].second;
      result++;
    }
    
    i++;
  }
  
  printf("%d \n", result);
  
  return 0;
}