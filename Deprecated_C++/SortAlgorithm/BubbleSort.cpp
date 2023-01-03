#include <iostream>
using namespace std;

void bubbleSort(int arr[], int length);

int main() {
  int arr[10] = { 4, 9, 5, 2, 8, 6, 0, 1, 3, 7 };
  
  bubbleSort(arr, 10);
  
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  
  return 0;
}

void bubbleSort(int arr[], int length) {
  int tmp;
  
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  
  return;
}