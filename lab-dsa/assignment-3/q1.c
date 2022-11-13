// singly linked list
#include <stdio.h>
#include <stdlib.h>
struct singlylinked{
    int data;
    struct singlylinked *next;
}*head;
typedef struct singlylinked node;

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
    head = (node*)malloc(sizeof(node));
    head->data = 5;
    head->next = NULL;
    insert_at_0(10);
    insert_at_1(20);
    delete(2);
    insert(7,1);
    insert(15, 2);
    display(head);
    delete_at_0();
    delete_at_1();
    display(head);
}

node* create(int data){
    struct singlylinked *new;
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
void insert_at_0(int data){

    if(head == NULL)
        head = create(data);
    else{
        node *ptr;
        ptr = (node*)malloc(sizeof(node));
        ptr = create(data);
        ptr->next = head;
        head = ptr;
    }
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
    if(head == NULL)
        head = create(data);
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
    ptr = head;
    while(ptr->next != NULL){
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1->next = NULL;
    free(ptr);
}