// convert infix to post and prefix
#include <stdio.h>
#include <stdlib.h>
struct linked {
	int data;
	struct linked* next;
}*head = NULL;
typedef struct linked node;
node* create(int data) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}
void insert(int data) {
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
		head = create(data);
	}
	else {
		node* ptr = (node*)malloc(sizeof(node));
		ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = create(data);
	}
}
void display() {
	if (head == NULL)
		printf("Empty!");
	else {
		node* ptr = (node*)malloc(sizeof(node));
		ptr = head;
		while (ptr != NULL) {
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}
int main() {
	short int choice = 0;
	do {
		printf("-------pre to post-------\n");
		printf("1. Insert\n2. Display\n0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			int num;
			scanf(" %d", &num);
			insert(num);
			break;
		case 2:
			display();
			break;
		default:
			break;
		}
	} while (choice != 0);
}