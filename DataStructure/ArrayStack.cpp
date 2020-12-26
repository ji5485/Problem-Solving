#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class ArrayStack {
  private:
    int index;
    int capacity;
    T *stack;
  
  public:
    explicit ArrayStack<T>(int _capacity): index(0), capacity(_capacity) {
      stack = new T[capacity];
    }
  
    void push(T element) {
      if (index == capacity) {
        printf("Stack is Full \n");
        return;
      }
      
      stack[index++] = element;
    }
  
    T pop() {
      return index == 0 ? (T) -1 : stack[index-- - 1];
    }
  
    int size() {
      return index;
    }
  
    int empty() {
      return index == 0 ? 1 : 0;
    }
  
    T top() {
      return index == 0 ? -1 : stack[index - 1];
    }
};

int main() {
  int size, n, value;
  char command[10];
  
  printf("Stack Size : ");
  scanf("%d", &size);
  ArrayStack<int> stack(size);
  
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