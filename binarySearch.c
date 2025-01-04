#include<stdio.h>
#include<stdlib.h>
int binarySearch(int low, int high, int data, int arr[]);
int main(){
    int n, search;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Enter the element to search : ");
    scanf("%d",&search);
    int result = binarySearch(0,n-1, search, arr);
    if(result==-1)printf("Search Not Found");
    else printf("Search Found at index %d",result);
}
int binarySearch(int low,int high, int data, int arr[]){
    if(high>=low){
        int mid=low+(high-low)/2;
        if(arr[mid]==data)
            return mid;
        if(arr[mid]>data)
            return binarySearch(low, mid-1, data, arr);
        return binarySearch(mid+1, high, data, arr);
    }
    return -1;
}