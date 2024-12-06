#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    char *arr;
    int top;
};

void initStack(struct Stack *s) {
    s->arr = (char *)malloc(MAX * sizeof(char));
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

char peek(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top];
}

void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
    } else {
        s->arr[++(s->top)] = value;
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    } else {
        return s->arr[s->top--];
    }
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack s;
    initStack(&s);

    int j = 0;  // Index for postfix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(&s, current);
        } else if (current == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Pop '(' from stack
        } else if (isOperator(current)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current)) {
                postfix[j++] = pop(&s);
            }
            push(&s, current);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
