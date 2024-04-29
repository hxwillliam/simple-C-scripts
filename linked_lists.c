#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *link;
} node;

void count_nodes(node *head){
    int count=0;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    node *ptr;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    printf("\n%d", count);
}

void print_data(node *head){
    if(head==NULL){
        printf("list is empty");
        return;
    }
    node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr=ptr->link;
    }
}

void append_end(node *head, int n){
    node *ptr, *new;
    ptr=head;
    new=(node*)malloc(sizeof(node));

    new->data=n;
    new->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=new;
}

bool is_ordered(node *head){
    if(head==NULL){
        printf("list is empty");
        return 0;
    }
    node *ptr = head;
    while(ptr->link != NULL){
        if(ptr->data > ptr->link->data){
            return false;
        }
        ptr = ptr->link;
    }
    return true;
}

node* pop_head(node *head){
    if(head==NULL){
        printf("list is empty");
        return NULL;
    }
    node *new = head->link;
    free(head);
    return new;
}

void reverse(node** head) {
    node* ptr = NULL;
    node* current = *head;
    node* new = NULL;
    while (current != NULL) {
        new = current->link;
        current->link = ptr;
        ptr = current;
        current = new;
    }
    *head = ptr;
}

void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}

int main(){

node *head = malloc(sizeof(node));
head->data=0;
head->link=NULL;

printf("insert numbers then terminate with 0:\n");
int n = 1;
while(n!=0){
    scanf("%d", &n);
    if(n!=0){
        append_end(head, n);
    }
}
head = pop_head(head);
printf("----------------------------------------------\n");
print_data(head);
printf("\nnumber of nodes: ");
count_nodes(head);
printf(is_ordered(head) ? "\nList ordered? YES" : "\nThis list is'nt ordered btw");
reverse(&head);
printf("\nReversed list: ");
print_list(head);

return 0;
}