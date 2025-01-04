//Stack Implementation Uisng Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
void push(int item){
    if(isFull()){
        printf("Stack Full \n");
        return ;
    }
    stack[++top]=item;
}
void pop(){
    if(isEmpty()){
        printf("Stack Empty \n");
        return ;
    }
    printf("Popped Item : %d\n",stack[top--]);
}
void peek(){
    if(isEmpty()){
        printf("Stack Empty \n");
        return;
    }
    printf("peeked Item is %d\n",stack[top]);
}
void display(){
    if(isEmpty()){
        printf("Stack Empty \n");
        return;
    }
    printf("Stack elements are : \n");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    int item,choice;
    while (1)
    {
        printf("Enter 1 to push 2 to pop 3 to peek 4 to display 0 to exit : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("Enter the item : ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }
    
}