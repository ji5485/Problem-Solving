#include <iostream>
using namespace std;

void swap(int &a, int &b);
void selectionSort(int arr[], int length);

int main() {
  int arr[10] = { 4, 9, 5, 2, 8, 6, 0, 1, 3, 7 };
  
  selectionSort(arr, 10);
  
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  
  return 0;
}

void swap(int &a, int &b) {
  int tmp;
  
  tmp = a;
  a = b;
  b = tmp;
  
  return;
}

void selectionSort(int arr[], int length) {
  int minIdx;
  
  for (int i = 0; i < length - 1; i++) {
    minIdx = i;
    
    for (int j = i + 1; j < length; j++) {
      if (arr[minIdx] > arr[j]) minIdx = j;
    }
    
    if (minIdx != i) swap(arr[i], arr[minIdx]);
  }
  
  return;
}