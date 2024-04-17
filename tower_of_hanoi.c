
#include <stdio.h>

void TOH(int *counter,int n, char start, char middle, char end){
    if(n==0) return;
    
    TOH(counter,n-1, start,end,middle);
    printf("\n%d) go from %c to %c", *counter,start,end);
    (*counter)++;
    TOH(counter,n-1,middle, start, end);
}

int main(){
    
    printf("enter number of discs: ");
    int n, counter=1;
    scanf("%d", &n);
    
    TOH(&counter,n,'A','B','C');
    
    return 0;
}
