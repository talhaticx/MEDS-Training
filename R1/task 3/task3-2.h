#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdbool.h>

#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define ISBN_LEN 20
#define GENRE_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char ISBN[ISBN_LEN];
    int publication_year;
    char genre[GENRE_LEN];
    unsigned int available_copies;
} Book;

static inline void print_book_details(const Book *b) {
    printf("----- Book Details -----\n");
    printf("Title            : %s\n", b->title);
    printf("Author           : %s\n", b->author);
    printf("ISBN             : %s\n", b->ISBN);
    printf("Publication Year : %d\n", b->publication_year);
    printf("Genre            : %s\n", b->genre);
    printf("Available Copies : %u\n", b->available_copies);
    printf("------------------------\n");
}

static inline bool is_book_available(const Book *b) {
    return b->available_copies > 0;
}

#endif
