#include "task3-2.h"

int main() {
    Book b1 = {
        .title = "The Pragmatic Programmer",
        .author = "Andrew Hunt",
        .ISBN = "978-0201616224",
        .publication_year = 1999,
        .genre = "Programming",
        .available_copies = 3
    };

    print_book_details(&b1);

    if (is_book_available(&b1))
        printf("Book is available for checkout.\n");
    else
        printf("Book is currently unavailable.\n");

    return 0;
}
