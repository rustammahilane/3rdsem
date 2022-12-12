// evaluate postfix notation
#include <stdio.h>
#include <stdlib.h>
struct singlylinked{
    int data;
    struct singlylinked *next;
}*top = NULL;
typedef struct singlylinked node;

node* create(int data){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

void push(int data){
    if(top == NULL){
        top = (node*)malloc(sizeof(node));
        top = create(data);
    }
    else{
        node *ptr;
        ptr = (node*)malloc(sizeof(node));
        ptr = create(data);
        ptr->next = top;
        top = ptr;
    }
}

void pop(){
    if(top == NULL)
        printf("already empty.");
    else{
        node* ptr;
        ptr = top;
        top  = top->next;
        free(ptr);
    }
}

// void display(node *head){
//     node *ptr = head;
//     while(ptr != NULL){
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

int evaluate(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
		switch(str[i]){
			case '-': (top->next->data) = (top-> next->data - top->data);
                         pop(top);
						break;
			case '+': (top->next->data) = (top-> next->data + top->data);
                         pop(top);
						break;
			case '/': (top->next->data) = (top-> next->data / top->data);
                         pop(top);
						break;
			case '*': (top->next->data) = (top-> next->data * top->data);
                         pop(top);
						break;
			case '%': (top->next->data) = (top-> next->data % top->data);
                         pop(top);
						break; 
			default :
             push((int)(str[i] - 48));
						break;
		}
	}
    return top->data;
}
int main()
{
    char str[50];
    printf("Enter postfix exp: ");
    scanf("%s", &str);
    printf("Equals to: ");
    printf("%d\n", evaluate(str));
}