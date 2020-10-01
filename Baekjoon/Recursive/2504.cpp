#include <iostream>
#include <string>
using namespace std;

string str;
int bracket(string::iterator &it, int mul, bool &check, int stack);

int main() {
  bool check = true;
  
  cin >> str;
  
  string::iterator it = str.begin();
  
  printf("%d \n", str.length() % 2 == 0 ? bracket(it, 1, check, 0) : 0);
  
  return 0;
}

int bracket(string::iterator &it, int mul, bool &check, int stack) {
  int ret = 0, nextMul;
  
  while (check && it != str.end()) {
    if (*it == ')' || *it == ']') {
      check = (*it == ')' && mul == 2) || (*it == ']' && mul == 3);
      
      it++;
      
      if (check) return ret == 0 ? mul : ret * mul;
      else return 0;
    }
    
    nextMul = *it == '(' ? 2 : 3;
    it++;
    ret += bracket(it, nextMul, check, stack + 1);
  }
  
  return check && stack == 0 ? ret : 0;
}