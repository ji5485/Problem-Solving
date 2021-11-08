#include <iostream>
#include <cmath>
using namespace std;

int getPosition(long long int number);
long long int getResult(int index, long long int number);
long long int INITIAL = (long long int) 1;

int main() {
  long long int a, b;
  
  scanf("%lld %lld", &a, &b);
  
  long long int result = getResult(getPosition(b), b) - getResult(getPosition(a - 1), a - 1);
  
  printf("%lld \n", result);
  
  return 0;
}

int getPosition(long long int number) {
  int n = 0;
  
  while (true) {
    if ((INITIAL << n) <= number && number < (INITIAL << (n + 1))) break;
    else n++;
  }
  
  return (int) n;
}

long long int getResult(int index, long long int number) {
  if (index == 0) {
    if (number == INITIAL) return INITIAL;
    else return (number + INITIAL) / (long long int) 2;
  }
  
  long long int result = 0;
  long long int cnt = number / (INITIAL << index);
  
  result += (INITIAL << index) * (cnt / (long long int) 2);
  if (cnt % (long long int) 2 == INITIAL) result += number - ((INITIAL << index) * cnt) + INITIAL;
  
  return result + getResult(index - INITIAL, number);
}