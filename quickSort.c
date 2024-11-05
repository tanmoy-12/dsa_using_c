#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1,j;
    for(j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high){
    int j=low;
    if(low<high){
        j=partition(arr, low, high);
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}