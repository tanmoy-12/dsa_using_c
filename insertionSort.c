#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the element : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
    printf("The sorted array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}