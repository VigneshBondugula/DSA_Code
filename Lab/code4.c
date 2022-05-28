#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* lc;
   struct node* rc; 
};
int Visit(struct node** node)
{
    if((*node)->data == 0 && !((*node)->lc) && !((*node)->rc))
    {
        *node=NULL;
    }
}
int height(struct node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int lheight = height(node->lc); 
        int rheight = height(node->rc); 
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
}  
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL)
    {printf("null ");return;} 
    if (level == 1) printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->lc, level-1); 
        printGivenLevel(root->rc, level-1); 
    } 
} 
void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
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
void Postorder(struct node** node)
{
    if(*node)
    {
        Postorder(&((*node)->lc));
        Postorder(&((*node)->rc));
        Visit(node);
    }
}
int main()
{
    int arr[8]={1,1,0,1,1,0,1,0};
    int n=8;
    struct node* root;
    root=insertLevelorder(arr,root,0,n);
    printLevelOrder(root);
    printf("\n");
    Postorder(&root);
    printLevelOrder(root);
}
