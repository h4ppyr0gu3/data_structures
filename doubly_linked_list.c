#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  struct element* left;
  struct element* right;
  char* data;
} element;

element* create_element(char* data) {
  element* new = malloc(sizeof(element));
  new -> data = data;
  new -> left = NULL;
  new -> right = NULL;
  return new;
}

void update_right(element* head, int index, char* data);
void update_left(element* head, int index, char* data);
void print_left(element* head);
void print_left(element* head);

void insert_left(element** head, char* data) {
  if (*head == NULL) {
    element* new = create_element(data);
    *head = new;
  } else {
    element* current = *head;
    while(current -> left != NULL) {
      current = current -> left;
    }
    element* new = create_element(data);
    current -> left = new;
    new -> right = current;
  }
}

void insert_right(element** head, char* data) {
  if (*head == NULL) {
    element* new = create_element(data);
    *head = new;
  } else {
    element* current = *head;
    while(current -> right != NULL) {
      current = current -> right;
    }
    element* new = create_element(data);
    current -> right = new;
    new -> left = current;
  }
}

void print_list(element* head) {
  if (head == NULL) printf("empty list\n");
  else {
    printf("Prints Head twice\n");
    printf("Printing Left:\n");
    print_left(head);
    printf("Printing Right:\n");
    print_right(head);
  }
}

void print_left(element* head) {
  element* current = head;
  while( current != NULL) {
    printf("current data: %s\n", current -> data);
    current = current -> left;
  }
}

void print_right(element* head) {
  element* current = head;
  while( current != NULL) {
    printf("current data: %s\n", current -> data);
    current = current -> right;
  }
}

void update(element* head, int index, int direction, char* data) {
  if (head == NULL) return;
  if(direction > 0) update_right(head, index, data);
  else if (direction < 0) update_left(head, index, data);
  else printf("Incorrect direction");
}

void update_left(element* head, int index, char* data) {
  element* current = head;

  for(int i = 1; i < index; i++) {
    if (current -> left == NULL) {
      printf("Index is out of range\n");
      return;
    }
    current = current -> left;
  }
  current -> data = data;
}

void update_right(element* head, int index, char* data) {
  element* current = head;

  for(int i = 1; i < index; i++) {
    if (current -> right == NULL) {
      printf("Index is out of range\n");
      return;
    }
    current = current -> right;
  }
  current -> data = data;
}

void handle_position_zero(element** head) {
  element* current = *head;
  element* left = current -> left;
  element* right = current -> right;
  if (left == NULL && right == NULL) *head = NULL;
  if (left == NULL && right != NULL) {
    right -> left = NULL;
    *head = right;
  } 
  if ( left != NULL && right == NULL) {
    left -> right == NULL;
    *head = left;
  }
  if (left != NULL && right != NULL) {
    left -> right = right;
    *head = left;

    free(current);
  }
  return;
}

void handle_right(element** head, int index) {
  element* current = *head;
  element* right = head;

  for(int i = 0; i < index; i++) {
    if (current == NULL) return;
    right = current;
    current = current -> right;
  }

  element* left = current -> left;
  left -> right = current -> right;
  free(current);
}

void handle_left(element** head, int index) {
  element* current = *head;
  element* left = *head;

  for(int i = 0; i > index; i--) {
    if (current == NULL) return;
    left = current;
    current = current -> left;
  }

  element* right = current -> right;
  right -> left = current -> left;
  free(current);
}

void remove_element(element** head, int index) {
  if (head == NULL) return;

  if (index == 0) {
    handle_position_zero(head);
    return;
  }
  if ( index >= 1) handle_right(head, index);
  else if (index <= -1 ) handle_left(head, index);
  else printf("Invalid value");
}

int main() {
  element* head = NULL;
  printf("\nPrinting empty list:\n\n");
  print_list(head);
  insert_left(&head, "creating head");
  insert_left(&head, "second left");
  insert_left(&head, "third left");
  insert_left(&head, "fourth left");
  insert_left(&head, "fifth left");
  insert_left(&head, "sixth left");
  insert_right(&head, "first right");
  insert_right(&head, "second right");
  insert_right(&head, "third right");
  printf("\nPrinting list with one on each side\n\n");
  print_list(head);
  update(head, 2, -3, "updated left");
  printf("\nPrinting after updating\n\n");
  print_list(head);
  printf("\nPrinting before removeing at 2, -2\n\n");
  remove_element(&head, 2);
  printf("\nPrinting after removeing at 2\n\n");
  print_list(head);
  printf("\nPrinting after removeing at -2\n\n");
  remove_element(&head, -2);
  print_list(head);
  printf("\nPrinting after removeing at 0\n\n");
  remove_element(&head, 0);
  print_list(head);
  printf("\nPrinting after removeing at -3\n\n");
  remove_element(&head, -3);
  print_list(head);
}

