// doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct doubly_linked{
    int data;
    struct doubly_linked *next;
    struct doubly_linked *prev;
}*head;
typedef struct doubly_linked node;

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
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;
    insert_at_0(5);
    insert_at_1(20);
    insert(15, 2);
    display(head);
    delete(2);
    display(head);
    insert(7,3);
    display(head);
    delete_at_0();
    delete_at_1();
    display(head);
}

node* create(int data){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
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
        head->prev = ptr;
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
        node *new = head;
        while(new->next != NULL)
            new = new->next;
        new->next = ptr;
        ptr->prev = new;
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
    new->prev = ptr;
    (ptr->next)->prev = new;
    ptr->next = new;
    insertion n-1 position not happen
}
void delete(int pos){
    if(head == NULL)
        printf("Head already NULL!!");
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = head;
        while(--pos)
            ptr = ptr->next;
        (ptr->prev)->next = ptr->next;
        (ptr->next)->prev = ptr->prev;
        free(ptr);
    }
}
void delete_at_0(){
    if(node_count() == 0)
        printf("already empty.");
    else{
        node* ptr;
        ptr = head;
        (head->next)->prev = NULL;
        head  = head->next;
        free(ptr);
    }
}
void delete_at_1(){
    node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    (ptr->prev)->next = NULL;
    free(ptr);
}