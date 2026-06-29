#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;


void initializeStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int isEmpty(Stack *s);


typedef struct {
    Stack s1;
    Stack s2;
} Queue;

void initializeQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int front(Queue *q);

int main() {
    Queue q;
    initializeQueue(&q);

    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                if (isEmpty(&(q.s1)) && isEmpty(&(q.s2))) {
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued element: %d\n", dequeue(&q));
                }
                break;
            case 3:
                if (isEmpty(&(q.s1)) && isEmpty(&(q.s2))) {
                    printf("Queue is empty\n");
                } else {
                    printf("Front element: %d\n", front(&q));
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

void initializeStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return s->items[(s->top)--];
    }
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void initializeQueue(Queue *q) {
    initializeStack(&(q->s1));
    initializeStack(&(q->s2));
}

void enqueue(Queue *q, int value) {
    push(&(q->s1), value);
}

int dequeue(Queue *q) {
    if (isEmpty(&(q->s2))) {
        if (isEmpty(&(q->s1))) {
            printf("Queue is empty\n");
            exit(1);
        }
        while (!isEmpty(&(q->s1))) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }
    return pop(&(q->s2));
}

int front(Queue *q) {
    if (isEmpty(&(q->s2))) {
        if (isEmpty(&(q->s1))) {
            printf("Queue is empty\n");
            exit(1);
        }
        while (!isEmpty(&(q->s1))) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }
    return q->s2.items[q->s2.top];
}
