#include<stdio.h>
#include<stdlib.h>
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
int height(struct node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int lheight = height(node->left); 
        int rheight = height(node->right); 
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
}  
void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) return; 
    if (level == 1) printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 

int Visit(struct node** node)
{
    return (*node)->data;
}

void Preorder(struct node** node)
{
    struct node* n=*node;
    if(n)
    {
        printf("%d ",Visit(node));
        Preorder(&(n->lc));
        Preorder(&(n->rc));
    }
}

void Inorder(struct node** node)
{
    if(*node)
    {
        Inorder(&((*node)->lc));
        printf("%d ",Visit(node));
        Inorder(&((*node)->rc));
    }
}
void Postorder(struct node** node)
{
    if(*node)
    {
        Postorder(&((*node)->lc));
        Postorder(&((*node)->rc));
        printf("%d ",Visit(node));
    }
}

void Preorderstack(struct node* node)
{
    if(node)
    {
        int top=-1;
        struct node* S[10];
        S[++top]=node;
        while(top>=0)
        {
            printf("%d ",Visit(&S[top]));
            node=S[top--];
            if((node)->rc)
            {
                S[++top]=(node)->rc;
            }
            if((node)->lc)
            {
                S[++top]=(node)->lc;
            }
        }
    }
}

void Inorderstack(struct node* node)
{
    if(node)
    {
        int top=-1;
        struct node* S[10];
        int B[10];
        S[++top]=node;
        B[top]=0;
        while(top>=0)
        {
            if(B[top]==1) printf("%d ",Visit(&S[top]));
            else
            {
                node=S[top];
                if((node)->rc)
                {
                    S[++top]=(node)->rc;
                    B[top]=0;
                }
                S[++top]=node;
                B[top]=1;
                if((node)->lc)
                {
                    S[++top]=(node)->lc;
                    B[top]=0;
                }
            }
        }
    }
}

int main()
{
    struct node* root;
    root=newNode(1);
    root->lc=newNode(2); 
    root->rc=newNode(3);
    Preorder(&root);
    printf("\n");    
    Preorderstack(root);
    printf("\n");    
    Postorder(&root);
    printf("\n");
    Inorder(&root);
    printf("\n");    
    // Inorderstack(root);

}
