#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  struct element* next;
  char* data;
} element;

element* create_element(char* data) {
  element* new = malloc(sizeof(element));
  new -> data = data;
  new -> next = NULL;
  return new;
}

void push(element** head, char* data) {
  if (*head == NULL) {
    element* new = create_element(data);
    *head = new;
  } else {
    element* current = *head;
    while(current -> next != NULL) {
      current = current -> next;
    }
    element* new = create_element(data);
    current -> next = new;
  }
}

void print_list(element* head) {
  if (head == NULL) printf("empty list\n");
  else {
    element* current = head;
    while( current != NULL) {
      printf("current data: %s\n", current -> data);
      current = current -> next;
    }
  }
}

void pop(element** head) {
  element* current = *head;
  if (head == NULL) return;
  if (current -> next == NULL) {
    *head = NULL;
    return;
  }

  element* prev;

  while(current -> next != NULL) {
    prev = current;
    current = current -> next;
  }
  prev -> next = NULL;
  free(current);
}

void top(element* head) {
  element* current = head;
  if (head == NULL) return;
  if (current -> next == NULL) {
    printf("top data: %s\n", current -> data);
    return;
  }

  while(current -> next != NULL) {
    current = current -> next;
  }
  printf("top data: %s\n", current -> data);
}

int main() {
  element* head = NULL;
  printf("\nPrinting empty list:\n\n");
  print_list(head);
  push(&head, "datta");
  push(&head, "more datta");
  push(&head, "some more datta");
  push(&head, "even more datta");
  printf("\nPrinting list after adding data:\n\n");
  print_list(head);
  printf("\nPrinting top:\n\n");
  top(head);
  pop(&head);
  pop(&head);
  printf("\nPrinting list after popping twice:\n\n");
  print_list(head);
}

