#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};
void push(struct Stack *stack, char item);
char pop(struct Stack *stack);
char peek(struct Stack *stack);
void display(struct Stack *stack);
void reverseString(char *str);

int main() {
    struct Stack stack;
    stack.top = -1; 

    int choice;
    char item, str[MAX_SIZE];

    do {
        printf("\n Stack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf(" %c", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != '\0') {
                    printf("Popped element: %c\n", item);
                }
                break;
            case 3:
                item = peek(&stack);
                if (item != '\0') {
                    printf("Top element: %c\n", item);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Enter a string to reverse: ");
                scanf("%s", str);
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}


void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty! Cannot peek.\n");
        return '\0';
    }
    return stack->items[stack->top];
}

void display(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%c ", stack->items[i]);
    }
    printf("\n");
}

void reverseString(char *str) {
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
  }
}
