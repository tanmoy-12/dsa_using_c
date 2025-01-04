#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* last = NULL;
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addBeg(int data){
    struct Node *curr = createNode(data);
    if(last == NULL){
        last = curr;
        curr->next = last;
        return;
    }
    curr->next = last->next;
    last->next = curr;
    return;
}
void addEnd(int data){
    struct Node *curr = createNode(data);
    if(last == NULL){
        last = curr;
        curr->next = last;
        return;
    }
    curr->next = last->next;
    last->next = curr;
    last = curr;
    return;
}
void display(){
    struct Node *temp = last->next;
    if(last == NULL)return;
    while(temp!=last){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",last->data);
    printf("\n");
}
void delBeg(){
    if(last == NULL)return;
    struct Node *temp = last->next;
    if(temp == last)last = NULL;
    else last->next = temp->next;
    free(temp);
}
void delEnd(){
    if(last == NULL)return;
    struct Node *temp = last->next;
    struct Node *prev = last;
    while(temp->next!=last){
        prev = temp;
        temp = temp->next;
    }
    prev->next = last;
    free(temp);
    last = prev;
}

int main(){
    int item,choice;
    while(1){
        printf("1. Add at beginning\n2. Add at end\n3. Delete at beginning\n4. Delete at end\n5. Display\n0. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("Enter the item to add at beginning: ");
                scanf("%d",&item);
                addBeg(item);
                break;
            case 2:
                printf("Enter the item to add at end: ");
                scanf("%d",&item);
                addEnd(item);
                break;
            case 3:
                delBeg();
                break;
            case 4:
                delEnd();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
