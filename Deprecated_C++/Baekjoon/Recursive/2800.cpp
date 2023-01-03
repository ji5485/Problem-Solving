#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string>
using namespace std;

void searchPair(string str);
void pushPair(int index, string str, int visible[]);
set<string> strSet;
vector<vector<int>> matching;
stack<int> tmp;

int main() {
  string str;
  int visible[200] = { 0 };
  
  cin >> str;
  
  searchPair(str);
  pushPair(0, str, visible);
  
  for (set<string>::iterator it = strSet.begin(); it != strSet.end(); it++) {
    if (it == strSet.begin()) continue;
    printf("%s \n", (*it).c_str());
  }
    
  return 0;
}

void searchPair(string str) {
  int index = 0;
  
  while (index < str.length()) {
    if (str[index] == '(') tmp.push(index);
    else if (str[index] == ')') {
      vector<int> pairIndex{ tmp.top(), index };
      tmp.pop();
      matching.push_back(pairIndex);
    }
    
    index++;
  }

  return;
}

void pushPair(int index, string str, int visible[]) {
  if (index == matching.size()) {
    string result = "";
    
    for (int i = 0; i < str.length(); i++) {
      if (visible[i]) continue;
      result += str[i];
    }
    
    strSet.insert(result);
    
    return;
  }
  
  visible[matching[index][0]] = visible[matching[index][1]] = 0;
  pushPair(index + 1, str, visible);
  visible[matching[index][0]] = visible[matching[index][1]] = 1;
  pushPair(index + 1, str, visible);
}