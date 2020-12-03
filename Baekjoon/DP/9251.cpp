#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getResult(int souIdx, int tarIdx);
int cache[1000][1000];
string sou, tar;

int main() {
  cin >> sou;
  cin >> tar;
  
  fill(&cache[0][0], &cache[999][1000], -1);
  printf("%d \n", getResult(0, 0));
  
  return 0;
}

int getResult(int souIdx, int tarIdx) {
  if (sou.length() == souIdx || tar.length() == tarIdx) return 0;
  
  int &ret = cache[souIdx][tarIdx];
  if (ret != -1) return ret;
  
  for (int i = tarIdx; i < tar.length(); i++) {
    if (sou[souIdx] == tar[i])
      ret = max(ret, 1 + getResult(souIdx + 1, i + 1));
  }
  
  ret = max(ret, getResult(souIdx + 1, tarIdx));
  
  return ret;
}