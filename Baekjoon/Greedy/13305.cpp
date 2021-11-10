#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, tmp, index = 0;
  unsigned long long result = 0;
  vector<int> price, distance;
  
  scanf("%d", &n);
  
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &tmp);
    distance.push_back(tmp);
  }
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    price.push_back(tmp);
  }
  
  int selected = price[0];
  
  while (n - 1 > index) {
    result += (unsigned long long) selected * distance[index];
        
    if (selected > price[index + 1]) selected = price[index + 1];

    index++;
  }
  
  printf("%llu \n", result);
  
  return 0;
}
