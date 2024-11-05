#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)temp[k++]=arr[i++];
    while(j<=high)temp[k++]=arr[j++];
    for(i=low;i<=high;i++)arr[i]=temp[i];
}
void mergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    mergeSort(arr, 0, n-1);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}