#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int getResult(int index, int value);
int num;
vector<int> vec;

int main() {
  int k, tmp;
  
  scanf("%d %d", &num, &k);
  
  for (int i = 0; i < k; i++) {
    scanf("%d", &tmp);
    vec.push_back(tmp);
  }
  
  printf("%d \n", getResult(to_string(num).length() - 1, 0));
  
  return 0;
}

int getResult(int index, int value) {
  if (index < 0) return num >= value ? value : 0;
  
  int result = 0;
  
  for (int i = 0; i < vec.size(); i++) {
    int nextVal = value + vec[i] * (int) pow(10, index);
    result = max(result, getResult(index - 1, nextVal));
  }
  
  if (index == to_string(num).length() - 1) result = max(result, getResult(index - 1, value));
  
  return result;
}