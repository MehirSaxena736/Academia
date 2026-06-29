#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function prototypes
void push(int stack[], int *top, int value);
int pop(int stack[], int *top);
int evaluatePostfix(char *postfix);

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);

    int result = evaluatePostfix(postfix);
    
    printf("Result of postfix expression: %d\n", result);

    return 0;
}

void push(int stack[], int *top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        stack[++(*top)] = value;
    }
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return stack[(*top)--];
    }
}

int evaluatePostfix(char *postfix) {
    int stack[MAX_SIZE];
    int top = -1;
    int i, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(stack, &top, postfix[i] - '0');
        } else if (postfix[i] == ' ' || postfix[i] == '\n') {
            continue; // Ignore spaces and newlines
        } else {
            operand2 = pop(stack, &top);
            operand1 = pop(stack, &top);
            switch (postfix[i]) {
                case '+':
                    push(stack, &top, operand1 + operand2);
                    break;
                case '-':
                    push(stack, &top, operand1 - operand2);
                    break;
                case '*':
                    push(stack, &top, operand1 * operand2);
                    break;
                case '/':
                    push(stack, &top, operand1 / operand2);
                    break;
                default:
                    printf("Invalid character in postfix expression\n");
                    exit(1);
            }
        }
    }
    return stack[top];
 
}

