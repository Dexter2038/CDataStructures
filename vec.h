#ifndef VEC_H
#define VEC_H
#include <stddef.h>

typedef struct Vec {
  int *arr;
  size_t size;
  size_t capacity;
} Vec;

Vec *vec_init();
int vec_push(Vec *vec, int value);
int vec_pop(Vec *vec, int *value);
int vec_get(Vec *vec, size_t index, int *value);
size_t vec_size(Vec *vec);
size_t vec_capacity(Vec *vec);
void vec_free(Vec *vec);

#endif // !VEC_H
