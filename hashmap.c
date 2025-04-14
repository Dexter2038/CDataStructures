#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int hash(int key, unsigned int bucket_count) {
  return key % bucket_count;
}

HashMap *hash_init() {
  HashMap *map = (HashMap *)malloc(sizeof(HashMap));
  if (map == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  unsigned int bucket_count = 16;
  HashMapNode **buckets =
      (HashMapNode **)malloc(bucket_count * sizeof(HashMapNode *));
  if (!buckets) {
    printf("Memory allocation failed\n");
    free(map);
    return NULL;
  }

  map->buckets = buckets;
  map->bucket_count = bucket_count;

  return map;
}

HashMap *hash_init_with_size(unsigned int bucket_count) {
  HashMap *map = (HashMap *)malloc(sizeof(HashMap));
  if (map == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  HashMapNode **buckets =
      (HashMapNode **)malloc(bucket_count * sizeof(HashMapNode *));
  if (!buckets) {
    printf("Memory allocation failed\n");
    free(map);
    return NULL;
  }

  map->buckets = buckets;
  map->bucket_count = bucket_count;

  return map;
}

int hash_get(HashMap *map, int key, int *value) {
  if (map == NULL) {
    return 0;
  }

  unsigned int index = hash(key, map->bucket_count);

  HashMapNode *bucket = map->buckets[index];

  while (bucket != NULL) {
    if (bucket->key == key) {
      *value = bucket->value;
      return 1;
    }
    bucket = bucket->next;
  }

  return 0;
}

int hash_remove(HashMap *map, int key, int *value) {
  if (map == NULL) {
    return 0;
  }

  unsigned int index = hash(key, map->bucket_count);

  HashMapNode *bucket = map->buckets[index];

  if (bucket->key == key) {
    *value = bucket->value;
    map->buckets[index] = bucket->next;
    return 1;
  }

  while (bucket->next != NULL) {
    if (bucket->next->key == key) {
      HashMapNode *free_bucket = bucket->next;
      bucket->next = bucket->next->next;
      *value = free_bucket->value;
      free(free_bucket);
      return 1;
    }
    bucket = bucket->next;
  }

  return 0;
}

int hash_set(HashMap *map, int key, int value) {
  if (map == NULL) {
    return 0;
  }

  unsigned int index = hash(key, map->bucket_count);

  HashMapNode *bucket = map->buckets[index];

  if (bucket == NULL) {
    HashMapNode *new_bucket = (HashMapNode *)malloc(sizeof(HashMapNode));
    if (new_bucket == NULL) {
      return 0;
    }

    new_bucket->key = key;
    new_bucket->value = value;
    new_bucket->next = NULL;

    map->buckets[index] = new_bucket;
    return 1;
  }

  if (bucket->key == key) {
    bucket->value = value;
    return 1;
  }

  while (bucket->next != NULL) {
    if (bucket->next->key == key) {
      bucket->next->value = value;
      return 1;
    }
    bucket = bucket->next;
  }

  HashMapNode *new_bucket = (HashMapNode *)malloc(sizeof(HashMapNode));
  if (new_bucket == NULL) {
    return 0;
  }

  new_bucket->key = key;
  new_bucket->value = value;
  new_bucket->next = NULL;

  bucket->next = new_bucket;
  return 1;
}

void hash_free(HashMap *map) {
  if (map == NULL) {
    return;
  }

  for (int i = 0; i < map->bucket_count; i++) {
    HashMapNode *current = map->buckets[i];
    while (current != NULL) {
      HashMapNode *next = current->next;
      free(current);
      current = next;
    }
  }
  free(map->buckets);
  free(map);
}

int hash_contains(HashMap *map, int key) {
  if (map == NULL) {
    return 0;
  }

  unsigned int index = hash(key, map->bucket_count);

  HashMapNode *bucket = map->buckets[index];

  while (bucket != NULL) {
    if (bucket->key == key) {
      return 1;
    }
    bucket = bucket->next;
  }

  return 0;
}

unsigned int hash_size(HashMap *map) {
  //
}
