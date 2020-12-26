#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

template <typename T>
struct NODE {
  struct NODE *next;
  T data;
};

template <typename T>
class LinkedListQueue {
  private:
    struct NODE<T> *head, *tail;
    int dataSize;
  
  public:
    LinkedListQueue<T>(): head(nullptr), tail(nullptr), dataSize(0) {};
  
    ~LinkedListQueue() {
      struct NODE<T> *curNode = head, *delNode;
      
      while (curNode->next != NULL) {
        delNode = curNode;
        free(delNode);
        
        curNode = curNode->next;
      }
    }
  
    void push(T element) {
      struct NODE<T> *newNode = (NODE<T>*) malloc(sizeof(NODE<T>));
      
      newNode->data = element;
      newNode->next = NULL;
      
      if (empty()) head = tail = newNode;
      else {
        tail->next = newNode;
        tail = tail->next;
      }
      
      dataSize++;
    }
  
    T pop() {
      if (empty()) {
        return (T) -1;
      };
      
      struct NODE<T> *delNode = head;
      T data = delNode->data;
      
      head = head->next;
      free(delNode);
      dataSize--;

      return data;
    }
  
    int size() {
      return dataSize;
    }
  
    int empty() {
      return dataSize == 0;
    }
  
    T front() {
      return empty() ? -1 : head->data;
    }
  
    T back() {
      return empty() ? -1 : tail->data;
    }
};

int main() {
  int n, value;
  char command[10];
  
  LinkedListQueue<int> queue;
  
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