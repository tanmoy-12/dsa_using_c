//Linked list Implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node *createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* addBeg(Node *r,int item){
    Node* newNode = createNode(item);
    if(r==NULL){
        return newNode;
    }
    else{
        newNode->next=r;
        r=newNode;
        return r;        
    }
}
Node* addEnd(Node *r,int item){
    Node* newNode = createNode(item);
    if(r==NULL){
        return newNode;
    }
    else{
        Node* temp = r;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        return r;
    }
}
Node *delBeg(Node *r){
    if(r==NULL){
        printf("List is Empty\n");
        return r;
    }
    Node *temp=r;
    r=r->next;
    free(temp);
    return r;
}
Node *delEnd(Node *r){
    if(r==NULL){
        printf("List is Empty\n");
        return r;
    }
    Node *temp=r;
    if(temp->next==NULL){
        r=r->next;
        free(temp);
        return r;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return r;
}
Node *delAny(Node *r,int item){
    if(r==NULL){
        printf("List is Empty\n");
        return r;
    }
    Node* temp=r;
    if(r->data==item){
        r=r->next;
        free(temp);
        return r;
    }
    while(temp->next!=NULL && temp->next->data!=item){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Element not found\n");
        return r;
    }
    Node* del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return r;
}
void display(Node *r){
    if(r==NULL){
        printf("List is Empty\n");
        return;
    }
    Node* temp=r;
    printf("List elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    Node *r=NULL;
    while(1){
        int choice;
        printf("Enter 1 to add at beginning 2 to add at end 3 to delete at beginning 4 to delete at end 5 to delete any node 6 to display 7 to exit : ");
        scanf("%d",&choice);
        int item;
        switch(choice){
            case 1:
                printf("Enter the item : ");
                scanf("%d",&item);
                r=addBeg(r,item);
                break;
            case 2:
                printf("Enter the item : ");
                scanf("%d",&item);
                r=addEnd(r,item);
                break;
            case 3:
                r=delBeg(r);
                break;
            case 4:
                r=delEnd(r);
                break;
            case 5:
                printf("Enter the item to be deleted: ");
                scanf("%d",&item);
                r=delAny(r,item);
                break;
            case 6:
                display(r);
                break;
            case 7:
                exit(0);
        }
    }
}