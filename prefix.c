#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX], result[MAX];
int top = -1, j = -1;

void push(char data) {
    stack[++top] = data;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '/': 
        case '*': return 2;
        case '+': 
        case '-': return 1;
        default: return -1;
    }
}

// Reverses a string and swaps parentheses
void reverseExpression(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }

    // Swap '(' and ')'
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

void convertToPostfix(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        char c = input[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[++j] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(')
                result[++j] = pop();
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c) && peek() != '(')
                result[++j] = pop();
            push(c);
        }
        i++;
    }

    while (top != -1) {
        result[++j] = pop();
    }
    result[++j] = '\0'; // Null-terminate the result
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);
    reverseExpression(infix);
    convertToPostfix(infix);
    strcpy(prefix, result);
    reverseExpression(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
