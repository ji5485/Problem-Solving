#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getResult(int index);
int cache[5000], MOD = 1000000;
string value;

int main() {
  cin >> value;
  fill(cache, cache + sizeof(cache) / sizeof(int), -1);
  
  if (value.length() == 0 || value[0] == '0') cout << 0;
  else cout << getResult(0);
  
  return 0;
}

int getResult(int index) {
  if (index == value.length()) return 1;
  
  int &ret = cache[index];
  if (ret != -1) return ret;
  
  ret = 0;
  
  int val = value[index] - '0';
  if (1 <= val && val <= 9) ret += getResult(index + 1);
  
  if (index < value.length() - 1 && val != 0) {
    val = 10 * val + (value[index + 1] - '0');
    if (1 <= val && val <= 26) ret += getResult(index + 2);
  }
  
  return ret = ret % MOD;
}