#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getResult(int index, int size, int value);
vector<int> bit;

int main() {
  int n, index;
  string str;
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    cin >> str;
    index = 0;

    for (char alphabet : str)
      index = index | (1 << (int) (alphabet - 'a'));
    
    bit.push_back(index);
  }
  
  printf("%d \n", getResult(0, n, 0));
  
  return 0;
}


int getResult(int index, int size, int value) {
  if (index >= size) return (int) value == (1 << 26) - 1;
  
  int result = 0;
  
  int nextVal = value | bit[index];
  result += getResult(index + 1, size, nextVal);
  result += getResult(index + 1, size, value);

  return result;
}