#ifndef LinkedList_H

#define LinkedList_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *create_node(int value);
void push_back(Node **list, int value);
void push_front(Node **list, int value);
Node *find(Node *list, int value);
int remove_node(Node **list, int value);
int count_nodes(Node *list);
void print(Node *list);
void free_list(Node *list);

#endif // !LinkedList_H
