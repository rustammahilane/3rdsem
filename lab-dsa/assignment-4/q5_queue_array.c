// queue using array
#include <stdio.h>
#include <stdlib.h>

struct queue{
	int size;
	int front, rear;
	int *Q;
};
typedef struct queue node;

void create(node *arr,int size){
	arr->size = size;
	arr->front = arr->rear = -1;
	arr->Q = (int*)malloc(arr->size*sizeof(int));
}

void enqueue(node *arr){
	if(arr->rear == arr->size -1)
		printf("Queue full!\n");
	else{
		int num;
		scanf(" %d", &num);
		arr->rear++;
		arr->Q[arr->rear] = num;
	}
}

void dequeu(node *arr){
	if(arr->front == arr->rear){
		printf("Queue is empty!\n");

	}
	else{ 
		arr->front++;
	}
}

void display(node *arr){
	if(arr->front == arr->rear)
		printf("Queue is empty!");
	else{
		for(int i = arr->front +1; i <= arr->rear; i++)
			printf("%d ",arr->Q[i]);
		printf("\n");
	}	
}

int main() {
	node *a;
	unsigned int size;
	printf("Enter size of Queue:");
	scanf("%u", &size);
	create(a, size+1);
	short int choice = 0;
	do {
		printf("-------queue-array------\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			enqueue(a);
			break;
		case 2:
			dequeu(a);
			break;
		case 3:
			display(a);
		default:
			break;
		}
	} while (choice != 0);
}