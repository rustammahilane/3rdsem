// paranthesis matching [{()}]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct singly_linked{
    char data;
    struct singly_linked *next;
};
typedef struct singly_linked node;

node* push(node *top,char data){
    if(top == NULL){
        top = (node*)malloc(sizeof(node));
        top->data = data;
        top->next = NULL;
    }
    else{
        node* ptr = (node*)malloc(sizeof(node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
    }
    return top;
}

node* pop(node* top){
    if(top == NULL)
        fprintf(stderr, "Stack Empty.\n");
    else{
        node *ptr;
        ptr = top;
        top = top->next;
        // free(ptr); ****shows error
    }
}

void display(node *top){
    while(top != NULL){
        printf("%c",top->data);
        top = top->next;
    }
}
bool is_balanced(char str[]){
    node *top = NULL;
    for(int i = 0; i < str[i]; i++){
        switch(str[i]){
            case '[':
            case '{':
            case '(': top = push(top, str[i]); break;

            case ']': if(top->data != '[') return false; top = pop(top); break;
            case '}': if(top->data != '{') return false; top = pop(top); break;
            case ')': if(top->data != '(') return false; top = pop(top); break;
        }
    }
    if(top == NULL)
        return true;
    else return false;
}

int main(){
    char str[50];
    printf("check balanced expression\nEnter exp: ");
    scanf("%s", str);

    printf("Balanced :");
    if(is_balanced(str)) printf(" yes\n");
    else printf(" no\n");
    return 0;
}