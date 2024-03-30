#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool Palindrome(char *str){
    int i=0,j=(strlen(str)-1);
    while(i<j) {
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    
    char str[99];
    printf("insert word: ");
    scanf("%s", str);
    
    printf(Palindrome(str)? "IS A PALINDROME": "NOT A PALINDROME");
    
    
    return 0;
}