#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct node {
  int element;
  struct node *next;
}node;

node *addnode(node *head, int val) {
  node *p1;
  p1=(node *)malloc(sizeof(node));
  if (p1 == NULL) {
    printf("Error in allocating memory\n");
    exit(1);
  }
  p1->next=NULL;
  p1->element=val;

  if (NULL != head)
    head->next=p1;
  head=p1;
  return head;
}

int listsize(node *head) {
  int size=0;
  while (head != NULL) {
    size++;
    head=head->next;
  }
  return size;
}

void clearlist(node *head) {
  node *p1;
  while (head != NULL) {
    p1=head->next;
    free(head);
    head=p1;
  }
}

int main() {
  node *list,*last;
  list=last=NULL;
  int val;

  printf("%d\n",sizeof(node));
  printf("Enter the data:");
  scanf("%d",&val);
  if (val >= 0) {
    list=addnode(list,val);
    last=list;
  }
  else {
    printf("No element added\n");
    return 0;
  }
  printf("Enter the data:");
  scanf("%d",&val);
  while (val >= 0) {
    last=addnode(last,val);
    printf("Enter the data:");
    scanf("%d",&val);
  }
  printf("List creating finished\n");

  last=list;
  printf("Number of elements in the list is %d\n",listsize(last));
  clearlist(list);

  return 0;
}
