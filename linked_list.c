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

void insert_last(element** head, char* data) {
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

void update(element* head, int index, char* data) {
  if (head == NULL) return;

  element* current = head;

  for(int i = 1; i < index; i++)
    current = current -> next;

  current -> data = data;
}

void remove_element(element** head, int index) {
  element* current = *head;
  if (head == NULL) return;
  if (index == 1) {
    *head = current -> next;
    return;
  }

  element* prev = head;

  for(int i = 1; i < index; i++) {
    if (current == NULL) return;
    prev = current;
    current = current -> next;
  }
  prev -> next = current -> next;
  free(current);
}

void retrieve_element(element* head, int index) {
  if (index < 1) return;
  if (index == 1 && head != NULL) printf("indexed data: %s\n", head -> data);
  element* current = head;
  for (int i = 1; i < index ; i++) {
    if (current == NULL) {
      printf("Element doesn't exist");
      return;
    }
    current = current -> next;
  }
  if (current == NULL) {
    printf("Element doesn't exist");
    return;
  }
  printf("indexed data: %s\n", current -> data);
}

int main() {
  element* head = NULL;
  printf("\nPrinting empty list:\n\n");
  print_list(head);
  insert_last(&head, "datta");
  insert_last(&head, "more datta");
  insert_last(&head, "some more datta");
  insert_last(&head, "even more datta");
  printf("\nPrinting list after adding data:\n\n");
  print_list(head);
  update(head, 3, "updated");
  printf("\nPrinting list after updating data:\n\n");
  print_list(head);
  remove_element(&head, 1);
  printf("\nPrinting list after removing head:\n\n");
  print_list(head);
  remove_element(&head, 2);
  printf("\nPrinting list after removing second element:\n\n");
  print_list(head);
  printf("\nPrinting list after adding more data:\n\n");
  insert_last(&head, "more datta at the end");
  insert_last(&head, "adding more again");
  print_list(head);
  printf("\nGetting element by index:\n\n");
  retrieve_element(head, 3);
  printf("\nGetting element out of range:\n\n");
  retrieve_element(head, 6);
}

