#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node** head,int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=*head;
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
int FCFA(struct node** head)
{
    struct node* p1=*head;
    struct node* p2=*head;
    while(!p2)
    {
        p1=p1->next;
        p2=p2->next;
        if(!p2)
        {
            p2=p2->next;
        }
        else
        {
            return 0;
        }
        if(p1==p2)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n,i,num;
    scanf("%d",&n);
    struct node* D=(struct node*)malloc(sizeof(struct node));
    
    //Input
    for(i=0;i<n-1;i++)
    {
        scanf("%d ",&num);
        insert(&D,num);
    }scanf("%d",&num);
    insert(&D,num);

    printf("%d",FCFA(&D));
}