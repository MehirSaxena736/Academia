#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* start, int data) {
    struct Node* newNode = createNode(data);
    if (start == NULL) {
        return newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        return newNode;
    }
}
struct Node* insertAtEnd(struct Node* start, int data) {
    struct Node* newNode = createNode(data);
    if (start == NULL) {
        return newNode;
    } else {
        struct Node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return start;
    }
}
struct Node* insertAtPosition(struct Node* start, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return start;
    }
    if (position == 1) {
        return insertAtBeginning(start, data);
    } else {
        struct Node* newNode = createNode(data);
        struct Node* temp = start;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position!\n");
            return start;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        return start;
    }
}
struct Node* deleteFromBeginning(struct Node* start) {
    if (start == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    free(temp);
    return start;
}
struct Node* deleteFromEnd(struct Node* start) {
    if (start == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        start = NULL;
    }
    free(temp);
    return start;
}
struct Node* deleteFromPosition(struct Node* start, int position) {
    if (start == NULL || position < 1) {
        printf("List is empty or invalid position!\n");
        return start;
    }
    if (position == 1) {
        return deleteFromBeginning(start);
    } else {
        struct Node* temp = start;
        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position!\n");
            return start;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
        free(temp);
        return start;
    }
}
struct Node* reverseList(struct Node* start) {
    struct Node *ptr = NULL;
    struct Node *temp = start;

    while (temp != NULL) {
        ptr = temp->prev;
        temp->prev = temp->next;
        temp->next = ptr;
        temp = temp->prev;
    }

    if (ptr != NULL) {
        start = ptr->prev;
    }
    return start;
}
void printList(struct Node* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

int main() {
    struct Node* start = NULL;
    int choice, data, position;

    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Reverse the linked list\n8. Print the list\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                start = insertAtBeginning(start, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                start = insertAtEnd(start, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                start = insertAtPosition(start, data, position);
                break;
            case 4:
                start = deleteFromBeginning(start);
                break;
            case 5:
                start = deleteFromEnd(start);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                start = deleteFromPosition(start, position);
                break;
            case 7:
                start = reverseList(start);
                break;
            case 8:
                printf("Current list: ");
                printList(start);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}

