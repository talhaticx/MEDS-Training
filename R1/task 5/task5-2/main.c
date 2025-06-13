#include "header.h"

int main()
{
  int *array = MALLOC(SIZE, integer);
  initialize_memory(array, SIZE);
  show_memory(array, SIZE);

  printf("\nResizing array to double the size...\n");
  int new_size = SIZE * 2;
  array = REALLOC(array, new_size, integer);

  // Populate new half
  initialize_memory(array + SIZE, SIZE);

  show_memory(array, new_size);

  free(array);  // always free memory
  return EXIT_SUCCESS;
}
