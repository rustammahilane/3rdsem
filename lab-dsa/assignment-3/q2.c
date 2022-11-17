// doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct doubly_linked{
    int data;
    struct doubly_linked *next;
    struct doubly_linked *prev;
}*head;
typedef struct doubly_linked node;
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
node* create(int data);
void insert_at_0(int data);
void display(node *head);
void insert_at_1(int data);
void insert(int data, int pos);
void delete(int pos);
void delete_at_0();
void delete_at_1();
int node_count();
int node_count();
int main()
{   
    int choice = 0;
    do{
        printf("------doubly-linked-list-------\n");
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
    node *ptr2 = head;
    printf("using next:");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr2 = ptr;
        ptr = ptr->next;
    }
    printf("\nusing prev:");
    while(ptr2 != NULL){
        printf("%d ", ptr2->data);
        ptr2 = ptr2->prev;
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
}
void delete(int pos){
    if(head == NULL)
        printf("Head already NULL!!");
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = head;
        while(pos--)
            ptr = ptr->next;
        (ptr->prev)->next = ptr->next;
        (ptr->next)->prev = ptr->prev;
        free(ptr);
    }
}
void delete_at_0(){
    if(node_count() == 0)
        printf("already empty.");
    else if(node_count() == 1)
        head = NULL;
    else{
        node* ptr;
        ptr = head;
        (head->next)->prev = NULL;
        head  = head->next;
        free(ptr);
    }
}
void delete_at_1(){
    if(node_count() == 0)
        printf("already empty.");
    else if(node_count() == 1)
        head = NULL;
    else{
    node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    (ptr->prev)->next = NULL;
    free(ptr);

    }
}
