// write a program to impliment stack using arrays

#include <stdio.h>
#define MAX 10
int top = -1;
void push(char *stack);
void pop(char *stack);
void display(char stack[]);
int main()
{
    short int choice = 0;
    char ch, stack[MAX];
    do{
        printf("-----stack-array-----\n");
        printf("1. DISPLAY\n2. PUSH\n3. POP\n0. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(stack);
            break;
        case 2:
            push(stack);
            break;
        case 3:
            pop(stack);
            break;
        default:
            break;
        }
    }while(choice != 0);
}
void push(char *stack){
    if(top == MAX-1)
        printf("Full!\n");
    else{
        char ch;
        printf("Enter push element: ");
        // NOTE: THERE IS A SPACE BEFORE '%c' ON REMOVING IT
        //       THE CODE ACCEPTS 'ch' AS NEWLINE CHARACTER
        scanf(" %c",&ch);
        if (top == -1){
            stack[0] = ch;
            top = 0;
        }
        else
            stack[++top] = ch;
        }
}
void pop(char *stack){
    if (top == -1)
        printf("Empty!\n");
    else{
        stack[top--] = '\0';
        printf("Pop done!\n");
    }
    printf("%d", top);
}
void display(char stack[]){
    int i = 0;
    while(stack[i] != '\0')
        printf("%c ", stack[i++]);
    printf("\n");
}