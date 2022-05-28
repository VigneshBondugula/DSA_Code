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

void print_list(struct node** head)
{
    struct node* temp=*head;
	while(temp!=NULL)						
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void reverse(struct node** head)
{
    struct node* p;
    struct node* n;
    struct node* c=*head;
    p=NULL;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    *head=p;
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

    reverse(&D);
    print_list(&D);
}