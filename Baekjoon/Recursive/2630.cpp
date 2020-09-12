#include <iostream>
using namespace std;

int paper[2] = { 0 }, paperMap[256][256] = { 0 };

bool checkSameColor(int size, int y, int x);
void getPaperCnt(int size, int y, int x);

int main() {
	int n;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &paperMap[i][j]);
	}
	
	getPaperCnt(n, 0, 0);
	
	printf("%d \n%d \n", paper[0], paper[1]);
	
	return 0;
}

bool checkSameColor(int size, int y, int x) {
	int initialValue = paperMap[y][x];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (initialValue != paperMap[y + i][x + j]) return false;
		}
	}
	
	paper[initialValue]++;
	return true;
}

void getPaperCnt(int size, int y, int x) {
	if (size == 1) {
		paper[paperMap[y][x]]++;
		return;
	}
	
	if (checkSameColor(size, y, x)) return;
	
	size /= 2;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			getPaperCnt(size, y + size * i, x + size * j);
	}
}