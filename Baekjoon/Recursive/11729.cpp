#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int to, int via);

int main() {
	int n;
	
	scanf("%d", &n);
	
	printf("%d \n", (int) pow(2, n) - 1);
	
	hanoi(n, 1, 3, 2);
	
	return 0;
}

void hanoi(int n, int from, int to, int via) {
	if (n == 1) {
		printf("%d %d \n", from, to);
		return;
	}
	
	hanoi(n - 1, from, via, to);
	printf("%d %d \n", from, to);
	hanoi(n - 1, via, to, from);
}