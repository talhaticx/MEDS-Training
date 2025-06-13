#include "header.h"

// Only in this file you can directly call malloc, realloc, etc.
#undef malloc
#undef realloc

void *alloc (size_t size){


  void *mempool;

  mempool = malloc(size);

  if (mempool != NULL) return mempool;
  
  else {
    printf("Out of memory");
    exit(EXIT_FAILURE);
  }

}

// Definition for initialize_memory
void initialize_memory(int * array, int size){
  srand(time(NULL));
  
  for (size_t i = 0; i < size; i++){
    int r = rand() % MAX_RAND;     // Get a random integer (0 to RAND_MAX)

    array[i] = r;
  }
}

// Definition for show_memory
void show_memory(int * array, int size){
  for (size_t i = 0; i < size; i++){
    printf("idx: %ld, value: %d\n", i, array[i]);
  }
}

// Definition for realloc wrapper
void *realloc_wrap(void *ptr, size_t new_size){
  void *new_mem = realloc(ptr, new_size);
  if (new_mem != NULL) return new_mem;

  else {
    printf("Realloc failed: Out of memory\n");
    exit(EXIT_FAILURE);
  }
}
