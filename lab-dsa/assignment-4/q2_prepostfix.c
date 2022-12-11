// convert infix to post and prefix
#include <stdio.h>
#include <stdlib.h>
struct linked {
	char data;
	struct linked* next;

};
typedef struct linked node;

node* create(int data) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

node* push(node *top, char data) {
	if (top == NULL) {
		top = (node*)malloc(sizeof(node));
		top = create(data);
	}
	else {
		node* ptr = (node*)malloc(sizeof(node));
		ptr = create(data);
		ptr->next = top;
		top = ptr;
	}
	return top;
}

node* pop(node *top){
	if(top->next != NULL){
		node *ptr = (node*)malloc(sizeof(node));
		ptr = top;
		top = top->next;
		free(ptr);
	}
	else{
		top = NULL;
	}		
}

void display(node *top) {

}

node* postfix(node* operand, char str[]){
	node *operator;
	for(int i = 0; str[i] != '\0'; i++){
		switch(str[i]){
			case '(':
			case '-':
			case '+':
			case '/':
			case '*':
			case '%': operator = push(operator, str[i]);
						break;
			case ')': operand = push(operand, operator->data);
						operator = pop(operator);
						break;
			default : operand = push(operand, str[i]);
						break;
		}
	}
	return operand;
}

int main() {
	char str[50];
	node *post;
	printf("Enter paranthesized infix notation:");
	printf("hi\n");
	scanf("%s", str);
	printf("bye");
	post = postfix(post, str);
}