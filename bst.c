#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *lchild,*rchild;
    int data;
};
struct Node *createNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory Error\n");
        return NULL;
    }
    newNode->data=data;
    newNode->lchild=newNode->rchild=NULL;
    return newNode;
}
struct Node *insert(struct Node *r, int item){
    struct Node *newNode=createNode(item);
    if(r==NULL){
        return newNode;
    }
    struct Node *temp=r,*parrent;
    while(temp!=NULL){
        parrent=temp;
        if(item<temp->data)
            temp=temp->lchild;
        else
            temp=temp->rchild;
    }
    if(item<parrent->data)parrent->lchild=newNode;
    else parrent->rchild=newNode;
    return r;
}
struct Node *delete(struct Node *r, int data){
    if(r==NULL)return r;
    if(r->rchild==NULL && r->lchild==NULL){
        return r;}
}
void inOrder(struct Node *r){
    if(r!=NULL){
        inOrder(r->lchild);
        printf("%d ",r->data);
        inOrder(r->rchild);
    }
}
void preOrder(struct Node *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
}
void postOrder(struct Node *r){
    if(r!=NULL){
        postOrder(r->lchild);
        postOrder(r->rchild);
        printf("%d ",r->data);
    }
}
int main(){
    int choice,item;
    struct Node *root=NULL;
    while(1){
        printf("1.Insert\n2.Inorder\n3.PreOrder\n4.PostOrder\n5.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d",&item);
                root=insert(root,item);
                break;
            case 2:
                inOrder(root);
                printf("\n");
                break;
            case 3:
                preOrder(root);
                printf("\n");
                break;
            case 4:
                postOrder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}