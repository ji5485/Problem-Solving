#include <iostream>
using namespace std;

int pages[3000][3000], cnt[3] = { 0 };

bool checkSamePage(int size, int y, int x);
void getPageCnt(int size, int y, int x);

int main() {
	int n, i;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &pages[i][j]);
	}
	
	getPageCnt(n, 0, 0);
	
	for (i = 0; i < 3; i++) printf("%d \n", cnt[i]);
	
	return 0;
}

bool checkSamePage(int size, int y, int x) {
	int initValue = pages[y][x];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (initValue != pages[y + i][x + j]) return false;
		}
	}
	
	cnt[initValue + 1]++;
	return true;
}

void getPageCnt(int size, int y, int x) {
	if (size == 1) {
		cnt[pages[y][x] + 1]++;
		return;
	}
	
	if (checkSamePage(size, y, x)) return;
	
	size /= 3;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			getPageCnt(size, y + size * i, x + size * j);
	}
}