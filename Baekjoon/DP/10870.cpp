#include <iostream>
#include <algorithm>
using namespace std;

int cache[21];
int getResult(int index);

int main() {
    int n;
    
    fill(cache, cache + sizeof(cache) / sizeof(int), -1);
    scanf("%d", &n);
    
    printf("%d \n", getResult(n));
    
    return 0;
}

int getResult(int index) {
    int &ret = cache[index];
    
    if (ret != -1) return ret;
    
    if (index == 0) return ret = 0;
    else if (index == 1) return ret = 1;
    
    return getResult(index - 1) + getResult(index - 2);
}