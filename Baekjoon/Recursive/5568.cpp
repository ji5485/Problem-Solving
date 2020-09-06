#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int results[5040], num[10], selectedIndex[10] = { 0 }, cnt = 0;
int joinValues(int n);
void getResult(int n, int r, int selected, vector<int>& value);

int main() {
	int n, r;
  vector<int> value;
	
	scanf("%d", &n);
	scanf("%d", &r);
	
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	
	getResult(n, r, 0, value);
	
	printf("%d \n", cnt);
	
	return 0;
}

int joinValues(vector<int>& value) {
	string result = "";
	
	for (int val : value) result += to_string(val);
	
	return atoi(result.c_str());
}

void getResult(int n, int r, int selected, vector<int>& value) {
	if (selected == r) {
    int result = joinValues(value);
    
    for (int j = 0; j < cnt; j++)
    	if (results[j] == result) return;
    
    results[cnt++] = result;
    return;
	}
  
  for (int i = 0; i < n; i++) {
    if ((bool) selectedIndex[i]) continue;

    selectedIndex[i] = 1;
    value.push_back(num[i]);
    getResult(n, r, selected + 1, value);

    selectedIndex[i] = 0;
    value.pop_back();
  }
}