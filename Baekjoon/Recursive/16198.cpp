#include <iostream>
#include <vector>
using namespace std;

int result = 0;
void getMaxEnergy(vector<int> weight, int sum);

int main() {
  int n;

  scanf("%d", &n);

  vector<int> weight(n);

  for (int i = 0; i < n; i++) scanf("%d", &weight[i]);

  getMaxEnergy(weight, 0);
  printf("%d \n", result);

  return 0;
}

void getMaxEnergy(vector<int> weight, int sum) {
  int popElement, energy;
  
  if (weight.size() == 2) {
    result = sum > result ? sum : result;
    return;
  }

  if (weight.size() == 2) return;
  
  for (int i = 1; i < weight.size() - 1; i++) {
    energy = weight[i - 1] * weight[i + 1];
    popElement = weight[i];
    weight.erase(weight.begin() + i);
    getMaxEnergy(weight, sum + energy);
    weight.insert(weight.begin() + i, popElement);
  }
}