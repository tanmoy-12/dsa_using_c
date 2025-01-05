#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX], result[MAX];
int top = -1, j=-1;
void push(char data){
    stack[++top] = data;
}
char pop(){
    if(top == -1)
        return '\0';
    return stack[top--];
}
char peek(){
    if(top == -1)
        return '\0';
    return stack[top];
}
int precedence(char op){
    switch(op){
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}
void convertToPostfix(char *input){
    int i=0;
    while(input[i] != '\0'){
        char c = input[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result[++j] = input[i];
        }
        else if(input[i] == '('){
            push(input[i]);
        }
        else if(input[i] == ')'){
            while(peek() != '(' )
                result[++j] = pop();
            pop();
        }
        else{
            while(peek()!= '(' && precedence(peek()) >= precedence(input[i]))
                result[++j] = pop();
            push(input[i]);
        }
        i++;
    }
    while(top != -1){
        result[++j] = pop();
    }
    result[++j] = '\0';
}
int main(){
    char input[100];
    printf("Enter infix expression: ");
    scanf("%s",input);
    convertToPostfix(input);
    printf("Postfix expression: %s\n", result);
    return 0;
}