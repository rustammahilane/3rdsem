// queue using array
#include <stdio.h>
#include <stdlib.h>

struct queue{
	int size;
	int front, rear;
	int *Q ;
};
typedef struct queue node;

void create(node *arr,int size){
	arr->size = size;
	arr->front = arr->rear = 0;
	arr->Q = (int*)malloc(arr->size*sizeof(int));
}

void enqueue(node *arr){
	if((arr->rear == arr->size && arr->front == 0) || (arr->rear + 1 == arr->front))
		printf("Queue full!\n"); 
	else{
		int num;
		scanf("%d", &num);
		if(arr->rear == arr->size)
			arr->rear = -1;
		arr->rear++;
		arr->Q[arr->rear] = num;
	}
}

void dequeu(node *arr){
	if(arr->front == arr->rear){
		printf("Queue is empty!\n");
	}
	else{ 
		if(arr->front == arr->size)
			arr->front = -1;
		arr->front++;
	}
}

void display(node *arr){
	if(arr->front == arr->rear)
		printf("Queue is empty!\n");
	else{
		int i = arr->front;
		if(arr->front < arr->rear){
			while(i < arr->rear)
			printf("%d ",arr->Q[++i]);
		}
		else{
			while(i < arr->size)	
				printf("%d ",arr->Q[++i]);
			i = -1;
			while(i < arr->rear)
				printf("%d ",arr->Q[++i]);
		}
		printf("\n");
	}	
}

int main() {
	node *a;
	int size;
	printf("Enter size of Queue:");
	scanf("%d", &size);
	create(a, size );
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