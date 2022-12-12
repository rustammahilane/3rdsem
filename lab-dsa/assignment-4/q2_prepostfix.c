// convert infix to post and prefix
#include <stdio.h>
#include <stdlib.h>
struct stack {
	char data;
	struct stack *next;

};
typedef struct stack node;

node* create(char data) {
	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

node* push(node *top, char data) {
	if (top == NULL) {
		top = (node*)malloc(sizeof(node));
		top->data = data;
		top->next = NULL;
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

int node_count(node *top){
	int count;
	while(top != NULL){
		count++;
		top = top->next;
	}
	return count;
}

// ERROR at ptr = ptrnext
void display(node *top) {
	node *ptr = (node*)malloc(sizeof(node));
	ptr = top;
	while(ptr != NULL){
		printf("%c", ptr->data);
		ptr = ptr->next;
	}
}

node* postfix(node* operand, char str[]){
	node *operator = NULL;
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
	// display(post);
	printf("%d", node_count(post));
}