#include <iostream>

int map[3072][6144] = { 0 };

void fillTriangle(int y, int x);
void fillStar(int size, int y, int x);

int main() {
	int n, start;
	
	scanf("%d", &n);
	
	fillStar(n, 0, n - 1);
	
	start = n;
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n * 2 - 1; j++) printf("%c", map[i][j] == 1 ? '*' : ' ');
	    printf("\n");
	    start++;
	}
	
	return 0;
}

void fillTriangle(int y, int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = i * -1; j <= i; j++) {
            if (i == 1 && j == 0) continue;
            map[y + i][x + j] = 1;
        }
    }
}

void fillStar(int size, int y, int x) {
    if (size == 3) {
        fillTriangle(y, x);
        return;
    }
    
    size /= 2;
    
    fillStar(size, y, x);
    fillStar(size, y + size, x - size);
    fillStar(size, y + size, x + size);
}