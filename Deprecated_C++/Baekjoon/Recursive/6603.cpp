#include <iostream>
#include <vector>
using namespace std;

vector<int> set, selected;

void printLotto(int size, int count, int current);

int main() {
	int n, tmp;
	
	while (true) {
	    scanf("%d", &n);
	    if (n == 0) break;
	    
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			set.push_back(tmp);
		}
		
		printLotto(n, 0, 0);
		selected.clear();
		set.clear();
		
		printf("\n");
	};
	
	return 0;
}

void printLotto(int size, int count, int current) {
	if (current > size) return;
	
	if (count == 6) {
		for (int j = 0; j < 6; j++) printf("%d ", selected[j]);
		printf("\n");
		return;
	}
	
	selected.push_back(set[current]);
	printLotto(size, count + 1, current + 1);
	selected.pop_back();
	printLotto(size, count, current + 1);
}