#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
   int data;
   struct node* lc;
   struct node* rc; 
};

struct node* newNode(int data) 
{ 
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  node->data = data; 
  node->lc = NULL; 
  node->rc = NULL; 
  return(node); 
}

int largest_BST1(struct node* node,struct node** head,int* min,int* max,int* size,int* check)
{
    if(node==NULL)
    {
        *check=1;
        return 0;
    }
    int temp=INT_MAX;
    int left=0;
    int right=0;

    *max=INT_MIN;
    int left_size;
    int right_size;
    left_size=largest_BST1(node->lc,head,min,max,size,check);
    if(*check ==1 && node->data > *max)
        left=1;

    temp=*min;

    *min=INT_MAX;

    right_size=largest_BST1(node->rc,head,min,max,size,check);
    if(*check ==1 && node->data < *min)
        right=1;

    if(temp<*min) *min=temp;
    if(node->data < *min) *min=node->data;
    if(node->data > *max) *max=node->data;

    if(left && right)
    {
        if(left_size+right_size+1 > *size) 
        {
            *size=left_size+right_size+1;
            *head=node;
        }
        return left_size+right_size+1;
    }
    else
    {
        *check=0;
        return 0;
    }
    

}

struct node* largest_BST(struct node* node)
{   
    int min=INT_MAX;
    int max=INT_MIN;
    int check=0;
    int size=0;
    struct node* head;

    largest_BST1(node,&head,&min,&max,&size,&check);
    return head;
}

int main()
{
    struct node* root;
    root=newNode(50);
    root->lc=newNode(2); 
    root->rc=newNode(5);
    root->lc->lc=newNode(3);
    root->lc->rc=newNode(4);
    root->rc->lc=newNode(1);
    root->rc->rc=newNode(8);
    /*           6
               /  \    
              2    10
             / \   / \
            3   4 1   8  
                            */   
    printf("%d",largest_BST(root)->data);

}