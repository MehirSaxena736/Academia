#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    char title[100];
    char author[100];
    int year;
};

// Global array to store book records
struct Book books[MAX_BOOKS];
int numBooks = 0;

// Function to add book information
void addBook() {
    if (numBooks < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]", books[numBooks].title);
        printf("Enter author name: ");
        scanf(" %[^\n]", books[numBooks].author);
        printf("Enter publication year: ");
        scanf("%d", &books[numBooks].year);
        numBooks++;
        printf("Book added successfully.\n");
    } else {
        printf("Maximum number of books reached.\n");
    }
}

// Function to display all book information
void displayBooks() {
    if (numBooks == 0) {
        printf("No books in the library.\n");
    } else {
        printf("Book Information:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Title: %s, Author: %s, Year: %d\n", books[i].title, books[i].author, books[i].year);
        }
    }
}

// Function to list all books by a given author
void listBooksByAuthor(char author[]) {
    int found = 0;
    printf("Books by author '%s':\n", author);
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Title: %s, Year: %d\n", books[i].title, books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by author '%s'.\n", author);
    }
}

// Function to count all books present in the library
int countBooks() {
    return numBooks;
}

int main() {
    int choice;
    char author[100];

    do {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. List Books by Author\n");
        printf("4. Count Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Enter author name: ");
                scanf(" %[^\n]", author);
                listBooksByAuthor(author);
                break;
            case 4:
                printf("Total number of books: %d\n", countBooks());
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

