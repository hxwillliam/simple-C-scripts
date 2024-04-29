#include <stdio.h>

int swap(int arr[], int start, int end){
    int pv =arr[end];
    int i=start-1;
    
    for(int j=start;j<=end-1;j++){
        if (arr[j] < pv)
		{
		  i++;
		  int temp = arr[i];
		  arr[i] = arr[j];
		  arr[j] = temp;
		}
	} 
      i++;
      int temp = arr[i];
      arr[i] = arr[end];
      arr[end] = temp;
 
 return i;   
}

void quicksort (int arr[], int start, int end){
    
    if(end<=start) return;
        
    int pv = swap(arr,start,end);
    swap(arr,start,pv-1);
    swap(arr,pv+1, end);
}



int main(){
    
	int n,i;
	
	printf("length of array= ");
	scanf("%d", &n);
    int arr[n];
	
    printf("inserisci array: \n");
    
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr,0, n-1);
    
    printf("sorted array: \n");
    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    
    return 0;
}