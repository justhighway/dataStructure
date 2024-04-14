#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* initHeadNode(Node* headNode) {
  headNode->data = 0;
  headNode->prev = headNode;
  headNode->next = headNode;

  return headNode;
}

Node* insertPosition(Node* headNode, Node* head, Node* position, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if (position == headNode->next) {
    newNode->next = headNode->next;
    headNode->next->prev = newNode;
    newNode->prev = headNode;
    headNode->next = newNode;
  }

  else if (position == headNode->prev) {
    head = headNode->prev;
    newNode->prev = headNode->prev;
    headNode->prev->next = newNode;
    newNode->next = headNode;
    headNode->prev = newNode;
  }

  else {
    printf("잘못된 position을 입력했습니다.\n");
    return NULL;
  }

  return newNode;
}

void printList(Node* head) {
  Node* current = head;
  printf("List: \n");

  while (current != NULL) {
    if (current->data == -1) {
      printf("headNode -> ");
    } else {
      printf("%d -> ", current->data);
    }
    current = current->next;
  }
  printf("NULL\n");
}

int main(void) {
  Node* headNode = (Node*)malloc(sizeof(Node));
  Node* head = headNode;

  headNode = initHeadNode(headNode);

  for (int i = 0; i < 5; i++) {
    head = insertPosition(headNode, head, headNode->next, i);
    printf("headNode: %p, head: %p\n", headNode, head);
    printf("headNode->next: %p, headNode->prev: %p\n", headNode->next,
           headNode->prev);
    printf("head->next: %p, head->prev: %p\n", head->next, head->prev);
    printf("\n");
  }

  return 0;
}