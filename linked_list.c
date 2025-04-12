#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  if (node == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  node->value = value;
  node->next = NULL;

  return node;
}

void push_back(Node **list, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  new_node->value = value;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
    return;
  }

  Node *current = *list;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void push_front(Node **list, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  new_node->value = value;
  new_node->next = *list;
  *list = new_node;
}

Node *find(Node *list, int value) {
  if (list == NULL) {
    return NULL;
  }

  if (list->value == value) {
    return list;
  }

  while (list->next != NULL) {
    list = list->next;
    if (list->value == value) {
      return list;
    }
  }

  return NULL;
}

int remove_node(Node **list, int value) {
  if (list == NULL || *list == NULL) {
    return 0;
  }
  Node *head = *list;

  if (head->value == value) {
    Node *next = head->next;
    free(head);
    *list = next;
    return 1;
  }

  Node *cur = head;
  Node *next = head->next;
  while (next != NULL) {
    if (next->value == value) {
      cur->next = next->next;
      free(next);
      return 1;
    }
    cur = next;
    next = next->next;
  }
  return 0;
}

int count_nodes(Node *list) {
  int size = 0;
  while (list != NULL) {
    size++;
    list = list->next;
  }
  return size;
}

void print(Node *list) {
  int size = count_nodes(list);
  char result[size * 12 + 3];
  int current = 1;
  result[0] = '[';
  while (list != NULL) {
    int written =
        snprintf(result + current, sizeof(result) - current, "%d", list->value);
    current += written;

    if (list->next != NULL) {
      result[current++] = ',';
      result[current++] = ' ';
    }

    list = list->next;
  }
  result[current++] = ']';
  result[current] = '\0';

  printf("%s\n", result);
}

void free_list(Node *list) {
  while (list != NULL) {
    Node *next = list->next;
    free(list);
    list = next;
  }
}
