#ifndef HASHMAP_H

#define HASHMAP_H

typedef struct HashMapNode {
  int key;
  int value;
  struct HashMapNode *next;
} HashMapNode;

typedef struct HashMap {
  HashMapNode **buckets;
  unsigned int bucket_count;
} HashMap;

unsigned int hash(int key, unsigned int bucked_count);
HashMap *hash_init();
HashMap *hash_init_with_size(unsigned int bucket_count);
int hash_get(HashMap *map, int key, int *value);
int hash_remove(HashMap *map, int key, int *value);
int hash_set(HashMap *map, int key, int value);
void hash_free(HashMap *map);
int hash_contains(HashMap *map, int key);
unsigned int hash_size(HashMap *map);

#endif // !HASHMAP_H
