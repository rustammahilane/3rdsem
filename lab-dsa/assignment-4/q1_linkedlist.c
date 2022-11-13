#include <stdio.h>
#include <stdlib.h>
struct doubly_linked{
    int data;
    struct doubly_linked *next;
    struct doubly_linked *prev;
}*head,*top;
typedef struct doubly_linked stack;
int isempty(){
    if(head == NULL)
    return 1;
    else 
    return 0;
}
void push(int data){
    if(isempty() == 1){
        head = (stack*)malloc(sizeof(stack));
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
        top = (stack*)malloc(sizeof(stack));
        top = head;
    }
    else{
        stack *ptr;
        ptr = (stack*)malloc(sizeof(stack));
        top->next = ptr;
        ptr->data = data;
        ptr->prev = top;
        ptr->next = NULL;
        top = ptr;
    }
    printf("Pushed %d.", data);
}
void pop(){
    if(isempty() == 1)
        printf("Empty!");
    else{
        if(top == head){
            free(top);
            head=NULL;
        }
        else{
            stack *ptr;
            ptr = (stack*)malloc(sizeof(stack));
            ptr = top;
            top = ptr->prev;
            top->next = NULL;
            free(ptr);
        }
        printf("Pop done.");
    }
}
void display(){
    printf("Stack: ");
    if(isempty() == 1)
        printf("Empty!");
    else{
        stack *ptr;
        ptr = (stack*)malloc(sizeof(stack));
        ptr = head;
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{

    int choice = 0;
    do{
        printf("-----------STACK------------\n");
        printf("1. Display\n2. Push\n3. Pop\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            int element = 0;
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 3:
            pop();
            break;
        case 0:
            break;
        default:
            printf("invalid input.");
            break;
        }
        printf("\n");
    }while(choice != 0);
}