#include <stdio.h>
#include <stdbool.h>


int at_index_of_n(int n){
  if(n<0){
    printf("must be a positive integer, try again ");
    return -n;
  }
  if(n==0) return 0;
  if(n==1) return 1;
  return at_index_of_n(n-1) + at_index_of_n(n-2);
}

bool isFibnum(int n,int a,int b){
  if(n<0){
    printf("must be a positive integer, try again ");
    return -n;
  }
  if(n==a || n==b) return true;
  if(n<b) return false;
  return isFibnum(n,b,a+b);
}

int main(){
  printf("\t\tSelect operation by number\n");
  printf("\t1) Calculate the fib number at inde2x n\n");
  printf("\t2) Verify if inputed number is a fib number\n");
  
  int choice;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nInsert index: ");
      int index;
      scanf("%d", &index);
      
      printf("%d", at_index_of_n(index));
      break;
    case 2:
      printf("Insert number: ");
      int num;
      scanf("%d", &num);
      
      printf(isFibnum(num,0,1)? "fib number detected":"that is NOT a fib number my fren");
      break;
  }

  return 0;
}
