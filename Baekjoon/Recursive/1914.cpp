#include <iostream>
#include <cmath>
using namespace std;

void multiply(int result[], int num);
void hanoi(int n, int from, int to, int via);

int main() {
	int n, result[50] = { 0 }, i;
	result[49] = 1;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) multiply(result, 2);
	
	result[49] -= 1;
	
	bool flag = false;
	for (i = 0; i < 50; i++) {
		if (result[i] != 0) flag = true;
		if (!flag) continue;
		printf("%d", result[i]);
	}
	
	printf("\n");
	
	if (n <= 20) hanoi(n, 1, 3, 2);
	
	return 0;
}

void multiply(int result[], int num) {
	int nextNum = 0;
	
	for (int i = 49; i >= 0; i--) {
		result[i] *= 2;
		result[i] += nextNum;
		nextNum = result[i] / 10;
		result[i] %= 10;
	}
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