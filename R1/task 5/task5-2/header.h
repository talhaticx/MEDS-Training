#ifndef _HEADER_GUARD_
#define _HEADER_GUARD_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_RAND 31

#define malloc "Do not call malloc directly in main!"
#define realloc "Do not call realloc directly in main!"

#define MALLOC(num,type)  (type *)alloc( (num)* sizeof(type) )
#define REALLOC(ptr, new_num, type) (type *)realloc_wrap(ptr, (new_num) * sizeof(type))


typedef int integer;

void *alloc(size_t);
void *realloc_wrap(void *, size_t);

void initialize_memory(int *, int);
void show_memory(int *, int);

#endif
