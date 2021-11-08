#include <iostream>

int map[6561][6561] = { 0 };

void fillStar(int size, int stairY, int stairX, int y, int x);

int main() {
	int n;
	
	scanf("%d", &n);
	
	fillStar(n, 0, 0, 0, 0);
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) printf("%c", map[i][j] == 0 ? ' ' : '*');
	    printf("\n");
	}
	
	return 0;
}

void fillStar(int size, int stairY, int stairX, int y, int x) {
    if (x == 1 && y == 1) return;
    
    if (size == 1) {
        map[stairY][stairX] = 1;
        return;
    }
    
    size /= 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            fillStar(size, stairY + size * i, stairX + size * j, i, j);
    }
}