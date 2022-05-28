#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* lc;
   struct node* rc; 
};
struct queue
{
    struct node* node;
    struct queue* next;
};
struct node* dequeue(struct queue** head)
{
    struct node *toDelete;
    if(head != NULL)
    {
        toDelete = (*head)->node;
        *head = (*head)->next;
        return toDelete;
    }
}
void enqueue(struct queue** head,struct node* node)
{
    struct queue* new_node = (struct queue*) malloc(sizeof(struct queue)); 
    new_node->node  = node; 
    new_node->next = (*head); 
    (*head)= new_node; 
}
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  node->data = data; 
  node->lc = NULL; 
  node->rc = NULL; 
  return(node); 
} 
int Visit(struct node** node)
{
    return (*node)->data;
}

void Levelorder(struct node* node)
{
    struct queue* Q=(struct queue*)malloc(sizeof(struct queue));
    enqueue(&Q,node);
    while(Q)
    {
        node=dequeue(&Q);
        Visit(&node);
        if(node->lc) enqueue(&Q,node->lc);
        if(node->rc) enqueue(&Q,node->rc);
    }
}
int main()
{
    struct node* root;
    root=newNode(1);
    root->lc=newNode(2); 
    root->rc=newNode(3);
    Levelorder(root); 
}