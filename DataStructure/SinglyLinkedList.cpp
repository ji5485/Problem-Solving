#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE {
  struct NODE *next;
  int data;
};

struct NODE *head = new struct NODE;

int front();
int back();
void push_front(int data);
void push_back(int data);
void pop_front();
void pop_back();
void insert(int data, int index);
void remove(int data);
void traverse();

int main() {
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
  
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    push_back(arr[i]);
  
  printf("Execute Traverse : ");
  traverse();
  
  printf("Execute Front : %d \n", front());
  printf("Execute Back : %d \n", back());
  printf("Execute Push Front : ");
  push_front(10);
  traverse();
  
  printf("Execute Pop Back : ");
  push_back(20);
  traverse();
  
  printf("Execute Insert : ");
  insert(123, 5);
  traverse();
  
  printf("Execute Remove : ");
  remove(123);
  traverse();
    
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    pop_back();
  
  return 0;
}

int front() {
  return head->next->data;
}

int back() {
  struct NODE *cur = head;
  
  while (cur->next != NULL)
    cur = cur->next;
  
  return cur->data;
}

void push_front(int data) {
  struct NODE *newNode = (NODE*) malloc(sizeof(NODE));
  struct NODE *front = head->next;
  
  newNode->data = data;
  newNode->next = front;
  
  head->next = newNode;
  
  return;
}

void push_back(int data) {
  struct NODE *newNode = (NODE*) malloc(sizeof(NODE));
  struct NODE *back = head;
  
  newNode->data = data;
  newNode->next = NULL;
  
  while (back->next != NULL)
    back = back->next;
  
  back->next = newNode;
  
  return;
}

void pop_front() {
  struct NODE *front = head->next, *nextNode = front->next;
  
  head->next = nextNode;
  free(front);
  
  return;
}

void pop_back() {
  struct NODE *back = head;
  
  while (back->next->next != NULL)
    back = back->next;
  
  struct NODE *willRemove = back->next;
  
  back->next = NULL;
  free(willRemove);
  
  return;
}

void insert(int data, int index) {
  struct NODE *cur = head;
  int curIndex = 0;
  
  while (cur != NULL) {
    if (curIndex != index) {
      cur = cur->next;
      curIndex++;
      continue;
    };
    
    struct NODE *newNode = (NODE*) malloc(sizeof(NODE));
    
    newNode->data = data;
    newNode->next = cur->next;
    cur->next = newNode;
    
    break;
  }
  
  return;
}

void remove(int data) {
  struct NODE *cur = head;
  
  while (cur->next != NULL && cur->next->data != data)
    cur = cur->next;
  
  struct NODE *nextNode = cur->next->next;
  
  free(cur->next);
  cur->next = nextNode;
  
  return;
}

void traverse() {
  struct NODE *cur = head->next;
  
  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
  
  return;
}