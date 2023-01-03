#include <iostream>
#include <string.h>
using namespace std;

const int MAX_SIZE = 100000;

template <typename T>
class ArrayDeque {
  private:
    int head, tail;
    T *deque;
  
  public:
    explicit ArrayDeque<T>(): head(MAX_SIZE / 2), tail(MAX_SIZE / 2) {
      deque = new T[MAX_SIZE];
    }
  
    ~ArrayDeque() {
      delete[] deque;
    }
  
    void push_front(T element) {
      if (head == 0) {
        printf("The Front of Deque is Full \n");
        return;
      }
      
      deque[--head] = element;
    }
  
    void push_back(T element) {
      if (tail == MAX_SIZE) {
        printf("The Back of Deque is Full \n");
        return;
      }
      
      deque[tail++] = element;
    }
  
    T pop_front() {
      T popped = empty() ? -1 : deque[head++];
      return popped;
    }
  
    T pop_back() {
      T popped = empty() ? -1 : deque[--tail];
      return popped;
    }
  
    int size() {
      return tail - head;
    }
  
    int empty() {
      return tail == head;
    }
  
    T front() {
      return empty() ? -1 : deque[head];
    }
  
    T back() {
      return empty() ? -1 : deque[tail - 1];
    }
  
    void traverse() {
      for (int i = head; i < tail; i++) printf("%d ", deque[i]);
      printf("\n");
    }
};

int main() {
  int n, value;
  char command[10];
  
  ArrayDeque<int> deque;
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    
    if (strcmp(command, "push") == 0) {
      scanf("%s %d", command, &value);
      if (strcmp(command, "front") == 0) deque.push_front(value);
      else if (strcmp(command, "back") == 0) deque.push_back(value);
    }
    else if (strcmp(command, "pop") == 0) {
      scanf("%s", command);
      if (strcmp(command, "front") == 0) printf("%d \n", deque.pop_front());
      else if (strcmp(command, "back") == 0) printf("%d \n", deque.pop_back());
    }
    else if (strcmp(command, "size") == 0) printf("%d \n", deque.size());
    else if (strcmp(command, "empty") == 0) printf("%d \n", deque.empty());
    else if (strcmp(command, "front") == 0) printf("%d \n", deque.front());
    else if (strcmp(command, "back") == 0) printf("%d \n", deque.back());
    else if (strcmp(command, "traverse") == 0) deque.traverse();
  }
  
  return 0;
}