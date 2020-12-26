#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class ArrayQueue {
  private:
    int head, tail;
    int capacity;
    int dataSize;
    T *queue;
  
  public:
    explicit ArrayQueue<T>(int _capacity): head(0), tail(0), dataSize(0), capacity(_capacity) {
      queue = new T[capacity];
    }
  
    ~ArrayQueue() {
      delete[] queue;
    }
  
    void push(T element) {
      if (dataSize == capacity) {
        printf("Queue is Full \n");
        return;
      }
      
      dataSize++;
      queue[tail] = element;
      tail = (tail + 1) % capacity;
    }
  
    T pop() {
      T popped = dataSize == 0 ? -1 : queue[head];
      head = (head + 1) % capacity;
      dataSize--;
      return popped;
    }
  
    int size() {
      return dataSize;
    }
  
    int empty() {
      return dataSize == 0;
    }
  
    T front() {
      return queue[head];
    }
  
    T back() {
      return tail == 0 ? queue[capacity - 1] : queue[tail - 1];
    }
};

int main() {
  int size, n, value;
  char command[10];
  
  printf("Queue Size : ");
  scanf("%d", &size);
  ArrayQueue<int> queue(size);
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    
    if (strcmp(command, "push") == 0) {
      scanf("%d", &value);
      queue.push(value);
    }
    else if (strcmp(command, "pop") == 0) printf("%d \n", queue.pop());
    else if (strcmp(command, "size") == 0) printf("%d \n", queue.size());
    else if (strcmp(command, "empty") == 0) printf("%d \n", queue.empty());
    else if (strcmp(command, "front") == 0) printf("%d \n", queue.front());
    else if (strcmp(command, "back") == 0) printf("%d \n", queue.back());
  }
  
  return 0;
}