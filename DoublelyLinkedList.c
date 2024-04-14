#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* initHeadNode() {
  Node* headNode = (Node*)malloc(sizeof(Node));
  headNode->data = 0;
  headNode->prev = headNode;
  headNode->next = headNode;

  return headNode;
}

Node* insertPosition(Node* headNode, Node* position, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if (position == headNode->next) {
    newNode->prev = headNode;
    headNode->next->prev = newNode;
    newNode->next = headNode->next;
    headNode->next = newNode;
  } else if (position == headNode->prev) {
    newNode->next = headNode;
    headNode->prev->next = newNode;
    newNode->prev = headNode->prev;
    headNode->prev = newNode;
  }

  return headNode;
}

Node* deletePosition(Node* headNode, Node* position) {
  if (position == headNode) {
    printf("리스트에 Node가 존재하지 않습니다.\n");
    return headNode;
  } else {
    position->prev->next = position->next;
    position->next->prev = position->prev;
    free(position);
  }

  return headNode;
}

void printList(Node* headNode) {
  Node* current = headNode;
  while (current->next != headNode) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("%d\n", current->data);
}

int main(void) {
  Node* headNode = initHeadNode();

  for (int i = 3; i > 0; i--) {
    headNode = insertPosition(headNode, headNode->next, i);
    printList(headNode);
  }
  for (int i = 4; i < 7; i++) {
    headNode = insertPosition(headNode, headNode->prev, i);
    printList(headNode);
  }
  for (int i = 0; i < 3; i++) {
    headNode = deletePosition(headNode, headNode->prev);
    printList(headNode);
  }
  for (int i = 0; i < 3; i++) {
    headNode = deletePosition(headNode, headNode->next);
    printList(headNode);
  }

  headNode = deletePosition(headNode, headNode->next);
  headNode = deletePosition(headNode, headNode->prev);
  printList(headNode);

  return 0;
}
