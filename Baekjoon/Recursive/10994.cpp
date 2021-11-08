#include <iostream>
#include <cmath>
using namespace std;

int map[400][400] = { 0 };
void printStar(int n, int y, int x);

int main() {
	int n, length;
	
	scanf("%d", &n);
	
	length = 1 + 4 * (n - 1);
	
	printStar(n, 0, 0);
	
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++)
			printf("%c", map[i][j] ? '*' : ' ');
		printf("\n");
	}
	
	return 0;
}

void printStar(int n, int y, int x) {
	if (n == 1) {
		map[y][x] = 1;
		return;
	}
	
	int size = 1 + 4 * (n - 1);
	
	for (int i = 0; i < size; i++)
		map[y + i][x] = map[y + i][x + size - 1] = map[y][x + i] = map[y + size - 1][x + i] = 1;
		
	printStar(n - 1, y + 2, x + 2);
}