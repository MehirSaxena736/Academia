#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;


void initializeQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmpty(Queue *q);

typedef struct {
    Queue q1;
    Queue q2;
} Stack;

void initializeStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int top(Stack *s);

int main() {
    Stack s;
    initializeStack(&s);

    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                if (isEmpty(&(s.q1)) && isEmpty(&(s.q2))) {
                    printf("Stack is empty\n");
                } else {
                    printf("Popped element: %d\n", pop(&s));
                }
                break;
            case 3:
                if (isEmpty(&(s.q1)) && isEmpty(&(s.q2))) {
                    printf("Stack is empty\n");
                } else {
                    printf("Top element: %d\n", top(&s));
                }
                break;
            case 4:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        exit(1);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q) {
    int item;
    if (q->front == -1) {
        printf("Queue Underflow\n");
        exit(1);
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return item;
    }
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

void initializeStack(Stack *s) {
    initializeQueue(&(s->q1));
}
