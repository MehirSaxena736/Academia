#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};


struct DoublyCircularLinkedList {
    struct Node *head;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(struct DoublyCircularLinkedList *list, int data) {
    struct Node *newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = list->head;
        newNode->prev = list->head->prev;
        list->head->prev->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void insertEnd(struct DoublyCircularLinkedList *list, int data) {
    struct Node *newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = list->head;
        newNode->prev = list->head->prev;
        list->head->prev->next = newNode;
        list->head->prev = newNode;
    }
}
void insertAtPosition(struct DoublyCircularLinkedList *list, int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertBeginning(list, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *current = list->head;
    int count = 1;
    while (count < position - 1 && current->next != list->head) {
        current = current->next;
        count++;
    }
    if (current->next == list->head && count != position - 1) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}


void deleteBeginning(struct DoublyCircularLinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node *lastNode = list->head->prev;
        list->head = list->head->next;
        list->head->prev = lastNode;
        lastNode->next = list->head;
    }
}


void deleteEnd(struct DoublyCircularLinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node *lastNode = list->head->prev;
        struct Node *secondLastNode = lastNode->prev;
        secondLastNode->next = list->head;
        list->head->prev = secondLastNode;
        free(lastNode);
    }
}

// Function to delete from a given position of the linked list
void deleteAtPosition(struct DoublyCircularLinkedList *list, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteBeginning(list);
        return;
    }
    struct Node *current = list->head;
    int count = 1;
    while (count < position && current->next != list->head) {
        current = current->next;
        count++;
    }
    if (current->next == list->head && count != position) {
        printf("Position out of range\n");
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

// Function to search an element in the linked list
void search(struct DoublyCircularLinkedList *list, int key) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *current = list->head;
    while (1) {
        if (current->data == key) {
            printf("Element found\n");
            return;
        }
        current = current->next;
        if (current == list->head)
            break;
    }
    printf("Element not found\n");
}

void display(struct DoublyCircularLinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}


int main() {
    struct DoublyCircularLinkedList list;
    list.head = NULL;
    int choice, data, position, key;
    while (1) {
        printf("\nDoubly Circular Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a given position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a given position\n");
        printf("7. Search for an element\n");
        printf("8. Display the linked list\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertBeginning(&list, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(&list, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&list, data, position);
                break;
            case 4:
                deleteBeginning(&list);
                break;
            case 5:
                deleteEnd(&list);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&list, position);
                break;
            case 7:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(&list, key);
                break;
            case 8:
                printf("Linked List: ");
                display(&list);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number from 1 to 9.\n");
        }
    }
return 0;
}

