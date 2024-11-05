#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapAdjust(int arr[], int i, int n){
    int j=2*i;
    int key=arr[i];
    do{
        if(j<n && arr[j]<arr[j+1])
            j++;
        if(key>arr[j])
            break;
        arr[j/2]=arr[j];
        j=2*i;
    }while(j<=n);
    arr[j/2]=key;
}
void makeHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)
        heapAdjust(arr,i,n);
}
void heapSort(int arr[], int n){
    makeHeap(arr,n);
    for(int i=n-1;i>0;i--){
        swap(&arr[i],&arr[0]);
        heapAdjust(arr,0,i);
    }
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    heapSort(arr, n);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}