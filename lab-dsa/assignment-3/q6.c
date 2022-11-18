// count no of nodes in a linked list
#include <stdio.h>
#include <stdlib.h>
struct singlylinked {
    int data;
    struct singlylinked* next;
}*head;
typedef struct singlylinked node;
int getdata(){
    int num;
    printf("Enter data:");
    scanf("%d", &num);
    return num;
}
node* create(int data){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}
void insert_at_1(int data){
    if(head == NULL){
        head = (node*)malloc(sizeof(node));
        head = create(data);
    }
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = create(data);
        node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}
int node_count(){
    node *ptr = head;
    int no_of_nodes = 0;
    while(ptr != NULL){
        no_of_nodes++;
        ptr = ptr->next;
    }
    return no_of_nodes;
}
void display(node *head){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{   
    int choice = 0;
    
    do{
         printf("1.Insert\n2.Display\n3.No of nodes\n0.Exit\n");
         printf("Enter choice: ");
         scanf("%d", &choice);
         switch(choice){
            case 1: 
                insert_at_1(getdata());
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("%d\n", node_count());
                break;
            case 0:
                break;
            default:
                break;
        }
    }while(choice != 0);
}