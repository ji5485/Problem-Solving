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
class LinkedListStack {
  private:
    struct NODE<T> *head, *tail;
  
  public:
    LinkedListStack<T>(): head((NODE<T>*) malloc(sizeof(NODE<T>))) {
      head->next = NULL;
      head->data = (T) NULL;
      
      tail = head;
    };
  
    ~LinkedListStack() {
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
      
      tail->next = newNode;
      tail = tail->next;
    }
  
    T pop() {
      struct NODE<T> *curNode = head;
      T data;
      
      while (curNode != NULL) {
        if (curNode->next != tail) {
          curNode = curNode->next;
          continue;
        }
        
        data = curNode->next->data;
        free(curNode);
        curNode->next = NULL;
        tail = curNode;
        return data;
      }

      return (T) -1;
    }
  
    int size() {
      struct NODE<T> *curNode = head;
      int index = 0;
      
      while (curNode->next != NULL) {
        curNode = curNode->next;
        index++;
      }
        
      return index;
    }
  
    int empty() {
      return head == tail;
    }
  
    T top() {
      return tail->data;
    }
};

int main() {
  int n, value;
  char command[10];
  
  LinkedListStack<int> stack;
  
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