// singly linked list
#include <stdio.h>
#include <stdlib.h>
struct singlylinked{
    int data;
    struct singlylinked *next;
}*head;
typedef struct singlylinked node;
int getdata();
int getposition();
node* create(int data);
void insert_at_0(int data);
void display(node *head);
void insert_at_1(int data);
void insert(int data, int pos);
void delete(int pos);
void delete_at_0();
void delete_at_1();
int node_count();

int main()
{   

    int choice = 0;
    do{
        printf("------singly-linked-list-------\n");
        printf("1.Insert at end\n2.Insert at first\n3.Insert at position\n"
        "4.Delete at end\n5.Delete at first\n6.Delete at position\n7.Display\n0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                insert_at_1(getdata());
                break;
            case 2:
                insert_at_0(getdata());
                break;
            case 3:
                insert(getdata(), getposition());
                break;
            case 4:
                delete_at_1();
                break;
            case 5:
                delete_at_0();
                break;
            case 6:
                delete(getposition());
                break;
            case 7:
                display(head);
                break;
            default:
                printf("Invalid input! terminating...");
                choice = 0;
                break;
        }
        
    }while(choice != 0);
    return 0;
}


void insert_at_0(int data){
    if(head == NULL){
        head = (node*)malloc(sizeof(node));
        head = create(data);
    }
    else{
        node *ptr;
        ptr = (node*)malloc(sizeof(node));
        ptr = create(data);
        ptr->next = head;
        head = ptr;
    }
}
int getdata(){
    int num;
    printf("Enter data:");
    scanf("%d", &num);
    return num;
}
int getposition(){
    int pos;
    printf("Enetr position:");
    scanf("%d", &pos);
    return pos;
}
void display(node *head){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
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
void insert(int data, int pos){
    if(pos == 0)
    insert_at_0(data);
    
    node* ptr =  (node*)malloc(sizeof(node));
    ptr = head;
    while(--pos){
        ptr = ptr->next;
    }
    node *new =(node*)malloc(sizeof(node));
    new  = create(data);
    new->next = ptr->next;
    ptr->next = new;
}
void delete(int pos){
    if(head == NULL)
        printf("Head already NULL!!");
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = head;
        while(--pos)
            ptr = ptr->next;
        ptr->next = (ptr->next)->next;
    }
}
void delete_at_0(){
    if(node_count() == 0)
        printf("already empty.");
    else{
        node* ptr;
        ptr = head;
        head  = head->next;
        free(ptr);
    }
}
void delete_at_1(){
    node *ptr, *ptr1;
    ptr = (node*)malloc(sizeof(node));
    ptr1 = (node*)malloc(sizeof(node));
    ptr = head;
    while(ptr->next != NULL){
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1->next = NULL;
    free(ptr);
}
node* create(int data){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
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