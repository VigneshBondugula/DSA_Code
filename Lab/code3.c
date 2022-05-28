#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* lc;
   struct node* rc; 
};
int moves=0;
int size(struct node* node)  
{   
  if (node==NULL)  
    return 0; 
  else     
    return(size(node->lc) + 1 + size(node->rc));   
} 
int coins(struct node* node)  
{   
  if (node==NULL)  
    return 0; 
  else     
    return(coins(node->lc) + (node->data) + coins(node->rc));   
} 
int Visit(struct node** node)
{
    int s=size(*node);
    int c=coins(*node);
    if(s>c)
    {
        return s-c;
    }    
    else
    {
        return c-s;
    }
}

struct node* insertLevelorder(int arr[],struct node* root,int i,int n)
{
    if(i<n)
    {
        struct node* node = (struct node*)malloc(sizeof(struct node)); 
        node->data = arr[i]; 
        root=node;
        node->lc=insertLevelorder(arr,root->lc,2*i+1,n);
        node->rc=insertLevelorder(arr,root->rc,2*i+2,n);   
    }
    return root;
}
int Preorder(struct node** node)
{
    struct node* n=*node;
    if(n)
    {
        moves+=Visit(node);
        Preorder(&(n->lc));
        Preorder(&(n->rc));
    }
}
int main()
{
    int arr[10]={0,0,3,0,3,0,0,2,0,2};
    int n=10;
    struct node* root;
    root=insertLevelorder(arr,root,0,n);
    Preorder(&root);
    printf("%d",moves);
}
