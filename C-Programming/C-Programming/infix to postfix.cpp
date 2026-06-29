#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void push(char stack[], int *top, char c);
char pop(char stack[], int *top);
int precedence(char c);
void infixToPostfix(char *infix, char *postfix);

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

void push(char stack[], int *top, char c) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        stack[++(*top)] = c;
    }
}

char pop(char stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return stack[(*top)--];
    }
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isspace(infix[i])) {
            continue;
        } else if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, &top, infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top); 
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        }
    }

    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j]='/0';
    
}
	
