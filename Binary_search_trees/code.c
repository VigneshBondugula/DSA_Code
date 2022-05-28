#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* lc;
    struct node* rc;
};

struct node* new_node(int data)
{
    struct node*temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->lc=NULL;
    temp->rc=NULL;
    return temp; 
}

void inorder(struct node* head)
{
    if(head!=NULL)
    {
        inorder(head->lc);
        printf("%d\n",head->data);
        inorder(head->rc);
    }
}

int insert(struct node** head,int data)
{
    struct node*temp=*head;
    if((*head)==NULL)
    {
        *head=new_node(data);
        return 0;
    }
    else if(data<(*head)->data) 
    {
        insert(&((*head)->lc),data);
    }
    else if (data > (*head)->data)
    { 
        insert(&((*head)->rc),data);
    }
}


struct node* insert2(struct node* head,int data)
{
    if(head==NULL)
    {
        return new_node(data);
    }
    if(data<head->data) 
    {
        head->lc=insert2(head->lc,data);
    }
    else if(data>head->data)
    { 
        head->rc=insert2(head->rc,data);
    }
    return head;
    
}

int main()
{
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    insert(&root, 50); 
    insert(&root, 30); 
    insert(&root, 20); 
    insert(&root, 40); 
    insert(&root, 70); 
    insert(&root, 60); 
    insert(&root, 80);  
    inorder(root); 
   
    return 0; 
}