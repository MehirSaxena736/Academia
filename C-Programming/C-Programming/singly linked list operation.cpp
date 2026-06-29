#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

void display() {
    struct Node* ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insertBeginning(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = start;
    start = temp;
}

void insertEnd(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        return;
    }

    struct Node* ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insertAtLocation(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be a positive integer.\n");
        return;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    if (position == 1) {
        temp->next = start;
        start = temp;
        return;
    }

    struct Node* ptr = start;
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Invalid position. Position exceeds the size of the list.\n");
        free(temp);
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteBeginning() {
    if (start == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = start;
    start = start->next;
    free(temp);
}

void deleteEnd() {
    if (start == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    struct Node* ptr = start;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;
}

void deleteAtLocation(int position) {
    if (position < 1) {
        printf("Invalid position. Position should be a positive integer.\n");
        return;
    }

    if (start == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* ptr = start;
    struct Node* temp;

    if (position == 1) {
        temp = start;
        start= start->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && ptr->next != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        printf("Invalid position. Position exceeds the size of the list.\n");
        return;
    }

    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
}
int searchElement(struct Node* head, int key)
{
	struct Node* current=head;
	while(current != NULL)
	{
		if(current ->data == key)
		return 1;
		
		current=current->next;
	}
	return 0;
}
int dectectloop(struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head;
	
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		
		if(slow == fast)
		return 1;
	}
}

void reverseLinkedList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev;
        prev = current; 
        current = next;
    }
    *head_ref = prev; 
}
int main() {
	struct Node* head=NULL;
    int choice, data, position,key;

    do {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Location\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Location\n");
        printf("8. search the element\n");
        printf("9. detecting a loop\n");
        printf("10. reversing the list\n");
        printf("11. Exit\n");
  
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtLocation(data, position);
                break;
            case 5:
                deleteBeginning();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtLocation(position);
                break;
            case 8:
                printf("enter the element to search.\n");
                scanf("%d",&key);
                if(searchElement){
                 printf("element found in the linked list\n");}
                else
                {
                	printf("element not found in the list");
				}
                break;
            case 9:
            	int detectloop(struct Node* head);
            	if(detectloop(head)){
            	printf("loop detected in the list\n");}
            	else
            	{
            		printf("not detected in the list\n");
				}
				break;
            case 10:
                reverseLinkedList;
                break;
            case 11:
                printf("Exiting the program.\n");
                break;
           	default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 11);

return 0;
}

