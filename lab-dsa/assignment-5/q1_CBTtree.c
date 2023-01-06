#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tree{
	char data;
	struct tree *rChild;
	struct tree *lChild;
};
typedef struct tree tree;

struct queue{
    tree* root;
    struct queue* next;
};
typedef struct queue queue_node;

// push in queue
void push(tree *root,queue_node **end){
    queue_node *new=(queue_node*)malloc(sizeof(queue_node));
    new->root=root;
    new->next=NULL;
    if(*end==NULL)
        *end=new;
    else{
        (*end)->next=new;
        *end=new;
    }
}

void pop(queue_node **front){
    if(*front==NULL)
        return;
    else{
        queue_node *temp=*front;
        *front=(*front)->next;
        free(temp);
    }
}

int queue_size(queue_node *front){
	int i = 0;
	queue_node* ptr = front;
	while(ptr){
		i++;
		ptr = ptr->next;
	}
	return i;
}

void visit(tree *root){
    printf("%c",root->data);
}

int Height(tree *root){
	if(!root) return 0;
	else{
		int i = 0;
		tree* ptr = root;
		while(ptr){
			++i;
			ptr = ptr->lChild;
		}
		return i;
	}
}

void Preorder(tree*root)
{
    if(root!=NULL)
    {
        visit(root);
        Preorder(root->lChild);
        Preorder(root->rChild);
    }
}

void Inorder(tree *root)
{
    if(root!=NULL)
    {
        Inorder(root->lChild);
        visit(root);
        Inorder(root->rChild);
    }
}

void Postorder(tree *root)
{
    if(root!=NULL)
    {
        Postorder(root->lChild);
        Postorder(root->rChild);
        visit(root);
    }
}
int Levelorder(queue_node *front,queue_node *end)
{
    static int i=0;
    if(front==NULL)
        return i;
    else{      
        int j = queue_size(front);
        while (j--)
        {
            tree *t_ptr=front->root;
            if(t_ptr!=NULL)
            {
                printf("%c",t_ptr->data);
                if(t_ptr->lChild!=NULL)
                    push(t_ptr->lChild,&end);
                if(t_ptr->rChild!=NULL)
                    push(t_ptr->rChild,&end);

                pop(&front);
            }
            else
                pop(&front);
        }
        ++i;
        return Levelorder(front,end);
    }
}

void insert(queue_node **front,queue_node **end,char data)
{
    queue_node *frnt=*front;
    queue_node *rear=*end;
    //new tree node
    tree *new=(tree*)malloc(sizeof(tree));
    new->data=data;
    new->lChild=new->rChild=NULL;
    //insert in queue
    push(new,&rear);
    *end=rear;
    //insert in CBT
    static int i=0;
    tree *root=frnt->root;
    if(i==0)
    {
        root->lChild=new;
        ++i;
    }
    else{
        root->rChild=new;
        i=0;
        pop(&frnt);
        *front=frnt;
    }
}
int main()
{
	tree* root = (tree*)malloc(sizeof(tree));
	root->data = 'A';
	root->lChild = root->rChild = NULL;

	queue_node *front, *end;
	front = (queue_node*)malloc(sizeof(queue_node));
	front->root = root;
	front->next = NULL;
	end = front;

	insert(&front,&end,'B');   
    insert(&front,&end,'C');
    insert(&front,&end,'D');
    insert(&front,&end,'E');
    insert(&front,&end,'F');
    insert(&front,&end,'G');
    insert(&front,&end,'H');
	/*	  
			   A
			 /	  \
			B	   C
		   / \    / \
		  D	  E  F   G	
		 /
		H

	*/
	printf("preorder: ");
	Preorder(root);
	printf("\nineorder: ");
	Inorder(root);
	printf("\npostorder: ");
	Postorder(root);

	queue_node *f = (queue_node*)malloc(sizeof(queue_node));
	f = front;
	f->root = root;
	f->next = NULL;
	queue_node* e = f;
	printf("\nlevelorder: ");
	Levelorder(f, e);
	printf("\nHeight of tree: %d\n", Height(root));
}