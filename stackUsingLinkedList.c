#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void Push(struct Node **head, int data) {
  struct Node *newN = createNode(data);
  newN->next = *head;
  *head = newN;
}

void Pop(struct Node **head) {
  if(head != NULL){
    struct Node *rm = *head;
    *head = (*head)->next;
    free(rm);
  }
  else printf("Stack Empty");
}

int Peek(struct Node *head){
  if(head!=NULL) return head->data;
  else {
    printf("Stack Empty");
    return -1;
  };
}
int main(void) {
  struct Node *head = NULL;
  Push(&head, 2);
  Push(&head, 3);
  printf("%d",Peek(head));
  Pop(&head);
  printf("%d",Peek(head));
}
