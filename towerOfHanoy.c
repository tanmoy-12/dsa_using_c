#include<stdio.h>
#include<stdlib.h>
int count = 0;
void TOH(int n, char src, char aux, char dest){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", src, dest);
        count++;    
        return;
    }
    TOH(n-1, src, dest, aux);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    count++;
    TOH(n-1, aux, src, dest);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Solution for Tower of Hanoi with %d disks:\n", n);
    TOH(n, 'A', 'C', 'B');
    printf("Total number of moves: %d\n", count);
    return 0;

}