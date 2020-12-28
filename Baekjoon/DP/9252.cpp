#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

pair<int, string> getResult(int souIdx, int tarIdx);
pair<int, string> cache[1000][1000];
string sou, tar;

int main() {
  cin >> sou;
  cin >> tar;
  
  fill(&cache[0][0], &cache[999][1000], make_pair(-1, ""));
  
  pair<int, string> result = getResult(0, 0);
  
  printf("%d \n", result.first);
  if (result.first != 0) printf("%s \n", result.second.c_str());
  
  return 0;
}

pair<int, string> getResult(int souIdx, int tarIdx) {
  if (sou.length() == souIdx || tar.length() == tarIdx) return make_pair(0, "");
  
  pair<int, string> &ret = cache[souIdx][tarIdx];
  if (ret.first != -1) return ret;
  
  if (sou[souIdx] == tar[tarIdx]) {
    ret.first = 1 + getResult(souIdx + 1, tarIdx + 1).first;
    ret.second = sou[souIdx] + getResult(souIdx + 1, tarIdx + 1).second;
  }
  else {
    pair<int, string> tmp1 = getResult(souIdx + 1, tarIdx), tmp2 = getResult(souIdx, tarIdx + 1);
    ret.first = max(tmp1.first, tmp2.first);
    ret.second = tmp1.first >= tmp2.first ? tmp1.second : tmp2.second;
  }
  
  return ret;
}