#include <iostream>
#include <string>
using namespace std;

string str;
int unzip(string::iterator &it, int mul);

int main() {
  char zipped[50];
  
  scanf("%s", zipped);
  str = zipped;
  
  string::iterator it = str.begin();
  
  printf("%d \n", unzip(it, 1));
  
  return 0;
}

int unzip(string::iterator &it, int mul) {
  int ret = 0, extra = 0;
  
  while (it != str.end()) {
    if (*it == ')') return (ret + extra) * mul;
    else if (*it == '(') {
      int nextMul = *(it - 1) - '0';
      it++;
      ret += unzip(it, nextMul);
      extra--;
    }
    else extra++;
    
    it++;
  }
  
  return (ret + extra) * mul;
}