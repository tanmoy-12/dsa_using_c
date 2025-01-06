#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    int height;
};
int max(int x, int y){
    return (x > y)? x : y;
}
int height(struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}
struct Node *rotateRight(struct Node *x){
    struct Node *y = x->lchild;
    struct Node *t = y->rchild;
    y->rchild = x;
    x->lchild = t;
    x->height = max(height(x->lchild), height(x->rchild)) + 1;
    y->height = max(height(y->lchild), height(y->rchild)) + 1;
    return y;
}
struct Node *rotateLeft(struct Node *x){
    struct Node *y = x->rchild;
    struct Node *t = y->lchild;
    y->lchild = x;
    x->rchild = t;
    x->height = max(height(x->lchild), height(x->rchild)) + 1;
    y->height = max(height(y->lchild), height(y->rchild)) + 1;
    return y;
}
struct Node *createNode(int key){
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr->lchild = curr->rchild = NULL;
    curr->data = key;
    curr->height = 1;
    return curr;  
}
int getBalance(struct Node *r){
    if (r == NULL)
        return 0;
    return height(r->lchild) - height(r->rchild);
}
struct Node *insert(struct Node *r, int key){
    if (r == NULL) return(createNode(key));
    if (key < r->data) r->lchild = insert(r->lchild, key);
    else if (key > r->data) r->rchild = insert(r->rchild, key);
    else return r;
    r->height = 1 + max(height(r->lchild), height(r->rchild));
    int balance = getBalance(r);
    if(balance < -1 && key > r->rchild->data) return rotateLeft(r);
    if(balance > 1 && key < r->lchild->data) return rotateRight(r);
    if(balance > 1 && key > r->lchild->data){
        r->lchild = rotateLeft(r->lchild);
        return rotateRight(r);
    }
    if(balance < -1 && key < r->rchild->data){
        r->rchild = rotateRight(r->rchild);
        return rotateLeft(r);
    }
}
 void inorder(struct Node *root){
    if(root == NULL) return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
 }
 void preorder(struct Node *root){
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
 }
 void postorder(struct Node *root){
    if(root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
 }
 struct Node* minNode(struct Node *r){
    while (r->lchild != NULL)
        r = r->lchild;
    return r;
 }
 struct Node *delNode(struct Node *r, int key){
    if (r == NULL) return r;
    if (key < r->data) r->lchild = delNode(r->lchild, key);
    else if (key > r->data) r->rchild = delNode(r->rchild, key);
    else{
        if(r->lchild == NULL){
            struct Node *temp = r->rchild;
            free(r);
            return temp;
        }
        else if(r->rchild == NULL){
            struct Node *temp = r->lchild;
            free(r);
            return temp;
        }
        else{
            struct Node *temp = minNode(r->rchild);
            r->data = temp->data;
            r->rchild = delNode(r->rchild, temp->data);
        }
    }
    r->height = 1 + max(height(r->lchild), height(r->rchild));
    int balance = getBalance(r);
    if(balance < -1 && getBalance(r->rchild) <= 0) return rotateLeft(r); // RR Case
    if(balance > 1 && getBalance(r->lchild) >= 0) return rotateRight(r); // LL Case
    if(balance > 1 && getBalance(r->lchild) < 0){ // LR Case
        r->lchild = rotateLeft(r->lchild);
        return rotateRight(r);
    }
    if(balance < -1 && getBalance(r->rchild) > 0){ //RL Case
        r->rchild = rotateRight(r->rchild);
        return rotateLeft(r);
    }
    return r;
 }
 int search(struct Node *r, int key){
    if (r == NULL) return 0;
    if (key == r->data) return 1;
    if (key < r->data) return search(r->lchild, key);
    return search(r->rchild, key);
}
 int main(){
    int choice,item;
    struct Node *root = NULL;
    while(1){
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Delete\n6. Search\n0. Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d",&item);
                root = insert(root, item);
                break;
            case 2:
                printf("Inorder traversal of the BST is : ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal of the BST is : ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal of the BST is : ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the item to delete: ");
                scanf("%d",&item);
                root = delNode(root, item);
                break;
            case 6:
                printf("Enter the item to search: ");
                scanf("%d",&item);
                if(search(root, item))printf("Found \n");
                else printf("Not found\n");
                break;
        }
    }
 }