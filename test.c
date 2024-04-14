#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* link;
} Node;

int main() {
  Node* head = NULL;
  printf("head가 가리키는 거: %p\n",
         head);  // 현재 head가 가리키고 있는 newNode의 주소
  printf("head가 저장된 곳: %p\n", &head);  // head 포인터 변수의 위치
  Node* newNode = (Node*)malloc(sizeof(Node));
  printf("newNode가 가리키는 거(자기 메모리 공간): %p\n",
         newNode);  // newNode가 가리키고 있는 주소
  printf("newNode 저장된 곳: %p\n",
         &newNode);  // newNode 포인터 변수의 위치

  newNode->data = 10;
  newNode->link = head;
  head = newNode;
  printf("\n");
  printf("head가 가리키고 있는 newNode의 주소: %p\n",
         head);  // 현재 head가 가리키고 있는 newNode의 주소
  printf("head 변수가 저장된 주소: %p\n", &head);  // head 포인터 변수의 위치
  printf("newNode가 가리키고 있는 head의 주소: %p\n",
         newNode);  // newNode가 가리키고 있는 주소
  printf("newNode 변수가 저장된 주소: %p\n",
         &newNode);  // newNode 포인터 변수의 위치
  printf("newNode->link 주소: %p\n", newNode->link);  // newNode->link의 주소

  return 0;
}
