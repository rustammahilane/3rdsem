// queue : FIFO
#include <stdio.h>
#include <stdlib.h>
struct linked {
	int data;
	struct linked* next;
}*front = NULL, *rear = NULL;
typedef struct linked node;
node* create(int data) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}
void enqueue(int data) {
	if (front == NULL) {
		front = (node*)malloc(sizeof(node));
		front = create(data);
		rear = (node*)malloc(sizeof(node));
		rear = front;
	}
	else {
		rear->next = create(data);
		rear = rear->next;
	}
}
void dequeue() {
	if (front == NULL)
		printf("Empty!");
	else{
		node* ptr = (node*)malloc(sizeof(node));
		ptr = front;
		front = front->next;
		free(ptr);
	}
}
void display() {
	if (front == NULL)
		printf("Empty!");
	else {
		node* ptr = (node*)malloc(sizeof(node));
		ptr = front;
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
		printf("-------queue-------\n");
		printf("1. Enqueue\n2. Display\n3. Dequeue\n0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			int num;
			scanf(" %d", &num);
			enqueue(num);
			break;
		case 2:
			display();
			break;
		case 3:
			dequeue();
			break;
		default:
			break;
		}
	} while (choice != 0);
}