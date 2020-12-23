#include <iostream>
#include <string.h>
using namespace std;

class Stack {
  private:
    int index;
    int arr[10000];
  
  public:
    Stack() {
      index = 0;
    }
  
    void push(int element) {
      arr[index++] = element;
    }
  
    int pop() {
      return index == 0 ? -1 : arr[index-- - 1];
    }
  
    int size() {
      return index;
    }
  
    int empty() {
      return index == 0 ? 1 : 0;
    }
  
    int top() {
      return index == 0 ? -1 : arr[index - 1];
    }
};

int main() {
  int n, value;
  char command[10];
  Stack stack;
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    
    if (strcmp(command, "push") == 0) {
      scanf("%d", &value);
      stack.push(value);
    }
    else if (strcmp(command, "pop") == 0) printf("%d \n", stack.pop());
    else if (strcmp(command, "size") == 0) printf("%d \n", stack.size());
    else if (strcmp(command, "empty") == 0) printf("%d \n", stack.empty());
    else if (strcmp(command, "top") == 0) printf("%d \n", stack.top());
  }
  
  return 0;
}