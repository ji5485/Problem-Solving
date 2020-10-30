#include <iostream>
#include <string>
using namespace std;

int number[1000000] = { 0 };
void getResult(int cnt, int len);

int main() {
  string num;
  
  cin >> num;
  
  for (int i = 0; i < num.length(); i++)
    number[i] = num[i] - '0';
  
  getResult(0, num.length());
  
  return 0;
}

void getResult(int cnt, int len) {
  if (len == 1) {
    printf("%d \n", cnt);
    printf(number[0] % 3 ? "NO" : "YES");
    return;
  }
  
  int sum = 0;
  
  for (int i = 0; i < len; i++)
    sum += number[i];
  
  string tmp = to_string(sum);
  
  for (int i = 0; i < tmp.length(); i++)
    number[i] = tmp[i] - '0';
  
  getResult(cnt + 1, tmp.length());
}