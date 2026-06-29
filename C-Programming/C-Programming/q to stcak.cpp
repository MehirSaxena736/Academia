#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

void enqueue(Stack *enqueueStack, int value) {
    push(enqueueStack, value);
}

int dequeue(Stack *enqueueStack, Stack *dequeueStack) {
    if (isEmpty(dequeueStack)) {
        while (!isEmpty(enqueueStack)) {
            push(dequeueStack, pop(enqueueStack));
        }
    }
    if (isEmpty(dequeueStack)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return pop(dequeueStack);
}

int main() {
    Stack enqueueStack, dequeueStack;
    initialize(&enqueueStack);
    initialize(&dequeueStack);

    int num, choice;

    while (1) {
        printf("Enter the operation to perform:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d", &num);
                enqueue(&enqueueStack, num);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&enqueueStack, &dequeueStack));
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

