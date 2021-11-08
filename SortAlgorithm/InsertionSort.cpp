#include <iostream>
using namespace std;

void insertionSort(int arr[], int length);

int main() {
  int arr[10] = { 4, 9, 5, 2, 8, 6, 0, 1, 3, 7 };
  
  insertionSort(arr, 10);
  
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  
  return 0;
}

void insertionSort(int arr[], int length) {
  int tmp, j;
  
  for (int i = 1; i < length; i++) {
    tmp = arr[i];
    
    for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
      arr[j + 1] = arr[j];
    
    arr[j + 1] = tmp;
  }
  
  return;
}