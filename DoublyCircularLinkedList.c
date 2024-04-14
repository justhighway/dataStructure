#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* initHeadNode(Node* headNode) {
  headNode->data = NULL;
  headNode->prev = headNode;
  headNode->next = headNode;

  return headNode;
}

Node* insert_position(Node* headNode, Node* position, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if (position == headNode->next) {
    newNode->next = headNode->next;
    newNode->prev = headNode;
    headNode->next->prev = newNode;
    headNode->next = newNode;
  }

  else if (position == headNode->prev) {
    newNode->prev = headNode->prev;
    newNode->next = headNode;
    headNode->prev->next = newNode;
    headNode->prev = newNode;
  }

  else {
    printf("잘못된 position을 입력했습니다.\n");
    return NULL;
  }

  return newNode;
}

int main(void) {
  Node* headNode = (Node*)malloc(sizeof(Node));
  headNode = initHeadNode(headNode);
  return 0;
}