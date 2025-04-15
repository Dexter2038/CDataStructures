#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

Vec *vec_init() {
  Vec *vec = (Vec *)malloc(sizeof(Vec));

  if (vec == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  int *arr = (int *)malloc(1 * sizeof(int));

  if (arr == NULL) {
    printf("Memory allocation failed\n");
    free(vec);
    return NULL;
  }

  vec->arr = arr;
  vec->size = 0;
  vec->capacity = 1;
  return vec;
}

int vec_push(Vec *vec, int value) {
  if (vec == NULL || vec->arr == NULL && vec->size != 0 && vec->capacity != 0) {
    return 0;
  }

  if (vec->size == vec->capacity) {
    int *new_arr = (int *)malloc(vec->capacity * 2 * sizeof(int));

    if (new_arr == NULL) {
      printf("Memory allocation failed\n");
      return 0;
    }

    vec->capacity *= 2;

    for (int i = 0; i < vec->size; i++) {
      new_arr[i] = vec->arr[i];
    }

    free(vec->arr);

    vec->arr = new_arr;
  }
  vec->arr[vec->size++] = value;
  return 1;
}

int vec_pop(Vec *vec, int *value) {
  if (vec == NULL || vec->size == 0 || value == NULL) {
    return 0;
  }

  *value = vec->arr[vec->size--];
  return 1;
}

int vec_get(Vec *vec, size_t index, int *value) {
  if (vec == NULL || vec->arr == NULL || index >= vec->size || value == NULL) {
    return 0;
  }

  *value = vec->arr[index];
  return 1;
}

size_t vec_size(Vec *vec) {
  if (vec == NULL) {
    return 0;
  }
  return vec->size;
}

size_t vec_capacity(Vec *vec) {
  if (vec == NULL) {
    return 0;
  }
  return vec->capacity;
}

void vec_free(Vec *vec) {
  if (vec == NULL) {
    return;
  }
  free(vec);
  free(vec->arr);
}
