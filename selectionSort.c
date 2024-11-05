#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_idx=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        swap(&arr[min_idx],&arr[i]);
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
    selection_sort(arr,n);
    printf("The sorted array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}