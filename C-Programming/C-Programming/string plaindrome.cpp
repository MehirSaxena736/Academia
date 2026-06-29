#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q);
void enqueue(Queue *q, char value);
char dequeue(Queue *q);
int isPalindrome(char *str);

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, char value) {
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

char dequeue(Queue *q) {
    char item;
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

int isPalindrome(char *str) {
    Queue q;
    initializeQueue(&q);
    int length = strlen(str);
    int i;


    for (i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            enqueue(&q, tolower(str[i]));
        }
    }

    for (i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            char dequeued = dequeue(&q);
            if (tolower(str[i]) != dequeued) {
                return 0; 
            }
        }
    }
    return 1; 


  
}
