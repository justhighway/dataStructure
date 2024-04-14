#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *link;  // 다음 구조체(Node)를 가리키는 포인터
} Node;               // 구조체 이름 정의

Node *insert_position(Node *head, int data, int position) {
  Node *newNode = (Node *)malloc(sizeof(Node));  // 새 노드 생성
  newNode->data = data;  // 새 노드에 데이터 저장

  if (position == 1) {  // 첫 번째 위치에 삽입하는 경우
    printf("Inserting %d at position %d\n", data, position);
    newNode->link =
        head;  // 새 노드의 다음 노드로 현재의 첫 번째 노드(head)를 설정
    head = newNode;  // head 포인터를 새 노드로 업데이트하여 새 노드를 리스트의
                     // 첫 번째 노드로 만듦
    return head;
  } else {  // 첫 번째 위치가 아닌 다른 위치에 삽입하는 경우
    Node *temp = head;  // position의 선행 node를 담을 포인터

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
      temp = temp->link;  // 삽입할 위치의 바로 이전 노드까지 이동
    }
    if (!temp) {  // 주어진 위치가 리스트의 범위를 벗어난 경우
      printf("Position %d is out of bounds\n", position);
      free(newNode);  // 새 노드를 메모리에서 해제
    } else {          // 삽입할 위치를 찾은 경우
      printf("Inserting %d at position %d\n", data, position);
      newNode->link =
          temp->link;  // 새 노드의 다음 노드로 temp의 다음 노드를 설정
      temp->link = newNode;  // temp의 다음 노드로 새 노드를 설정하여 리스트에
                             // 새 노드를 연결
    }
  }
  return head;  // 업데이트된 리스트의 head 포인터 반환
}

Node *delete_position(Node *head, int position) {
  printf("Deleting node at position %d\n", position);
  if (!head) {  // head가 가리키는 게 NULL(node가 없다면)
    printf("List is empty\n");
    return NULL;
  }
  if (position == 1) {  // 첫 번째 위치를 삭제하는 경우
    Node *temp = head;  // 첫 번째 노드를 임시 저장
    head = head->link;  // head를 두 번째 노드로 변경
    free(temp);  // 임시 저장한 기존 첫 번째 노드 할당 해제
    return head;
  }
  // 그 외의 경우
  Node *temp = head,
       *prev = NULL;  // 첫 번째 노드를 임시 저장하고 선행 노드는 null로 초기화
  for (int i = 1; i < position && temp != NULL; i++) {
    prev = temp;        // 선행 노드를 temp의 주소로 저장
    temp = temp->link;  // temp를 다음 노드로 이동
  }
  if (temp == NULL) {  // temp를 이동하면서 NULL을 만났다면
    printf("Position out of bounds\n");
  } else {
    prev->link = temp->link;  // 선행 노드의 link를 다음 노드의 link로 재할당
    free(temp);               // 삭제할 노드를 할당 해제
  }
  return head;
}

int *search_list(Node *head, int x) {
  Node *p = head;
  int index = 1;
  while (p != NULL) {
    if (p->data == x) {
      printf("Found %d at position %d\n", x, index);
      return 0;
    }
    p = p->link;
    index++;
  }
  printf("%d Not found\n", x);
  return 0;
}

// 리스트 출력하는 함수
void print_list(Node *head) {  // Node type의 포인터
  printf("Linked List Now: ");
  Node *current = head;  // NodeList의 첫번째(head)부터 저장
  while (current) {      // 마지막 Node가 아닐 때까지
    printf("%d ", current->data);
    if (current->link) {  // 마지막 Node가 아니면 `->` 붙이기
      printf("-> ");
    }
    current = current->link;  // 현재 구조체가 가리키고 있는 주소 업데이트
  }
  printf("\n\n");
}

int main(void) {
  Node *head = NULL;  // LinkedList 초기화
  head = insert_position(head, 10, 1);
  head = insert_position(head, 20, 1);
  head = insert_position(head, 30, 3);  // 마지막에 삽입
  head = insert_position(head, 40, 2);
  head = insert_position(head, 40, 10);
  print_list(head);

  head = delete_position(head, 3);
  head = delete_position(head, 3);  // 마지막 노드 제거
  head = delete_position(head, 1);
  print_list(head);

  search_list(head, 20);
  search_list(head, 40);

  return 0;
}
