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
        else if(item>temp->data)
            temp=temp->rchild;
        else
            temp=temp->rchild;
    }
    if(item<parrent->data)parrent->lchild=newNode;
    else parrent->rchild=newNode;
    return r;
}
struct Node *minNode(struct Node *root){
    if(root==NULL || root->lchild==NULL)return root;
    struct Node *temp=root;
    while(temp->lchild!=NULL)temp=temp->lchild;
    return temp;
}
struct Node *delete(struct Node *root, int data){
    if(root==NULL)return root;
    if(data<root->data)root->lchild = delete(root->lchild,data);
    else if (data>root->data)root->rchild = delete(root->rchild,data);
    else{
        if(root->lchild==NULL){
            struct Node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild==NULL){
            struct Node *temp = root->lchild;
            free(root);
            return temp;
        }
        else{
            struct Node *succ=minNode(root->rchild);
            root->data=succ->data;
            root->rchild=delete(root->rchild,succ->data);
            return root;
        }
    }
    return root;
}
void inOrder(struct Node *root){
    if(root == NULL)return;
    inOrder(root->lchild);
    printf("%d ",root->data);
    inOrder(root->rchild);
}
void preOrder(struct Node *root){
    if(root == NULL)return;
    printf("%d ",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);    
}
void postOrder(struct Node *root){
    if(root == NULL)return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ",root->data);
}
int externalNodes(struct Node *root){
    if(root==NULL)return 0;
    if(root->lchild==NULL && root->rchild==NULL)
        return 1;
    return externalNodes(root->lchild)+externalNodes(root->rchild);
}
 int internalNodes(struct Node *root){
    if(root==NULL)return 0;
    if(root->lchild!=NULL || root->rchild!=NULL)
        return 1+internalNodes(root->lchild)+internalNodes(root->rchild);
    return 0;
 }
int main(){
    int choice,item;
    struct Node *root=NULL;
    while(1){
        printf("1.Insert\n2.Inorder\n3.PreOrder\n4.PostOrder\n5.Delete\n6. Internal Nodes\n7. External Node\n0.Exit\nEnter your choice : ");
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
                printf("Enter the item to delete: ");
                scanf("%d",&item);
                root=delete(root,item);
                break;
            case 6:
                printf("Internal Nodes: %d\n", internalNodes(root));
            case 7:
                printf("External Nodes: %d\n", externalNodes(root));
            case 0:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}