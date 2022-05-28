#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* table[10];
void create_table()
{
	for(int i=0;i<10;i++)
    {
        struct node* head=(struct node*)malloc(sizeof(struct node));
        head->data=0;
        head->next=NULL;
        table[i]=head;
    }
}
void change_value_at_index(struct node** head,int index,int value)
{
    struct node* temp=*head;
    for(int i=0;i<index;i++)
    {
        temp=temp->next;
    }
    temp->data=value;
}
int len_of_linkedlist(struct node** head)
{
	int l=0;
	struct node* temp=*head;
	while(temp!=NULL)
	{
		temp=temp->next;
		l++;
	}
	return l;
}
int get_value_at_index(struct node** head,int index)
{
    struct node* temp=*head;
    for(int i=0;i<index;i++)
    {
        temp=temp->next;
    }
    return temp->data;
}
void insert(int k,int index)
{
    struct node* value=(struct node*)malloc(sizeof(struct node));
    value->data=k;
    value->next=NULL;
    struct node* head=table[index];
    while(table[index]->next!=NULL)
    {
        table[index]=table[index]->next;
    }
    table[index]->next=value;
    table[index]=head;
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

int main()
{
	int k=0,len=0,i=0,d,x=1,minimum,t=0,j=0,index=0;
	int C[10];
	scanf("%d",&d);
	scanf("%d",&len);
	int A[len];
	for(i=0;i<len-1;i++)
	{
		scanf("%d ",&A[i]);
	}scanf("%d",&A[i]);
	create_table();
	while(d>1)
	{
		x*=10;
		d--;
	}
	for(i=0;i<len;i++)
	{
		insert(A[i],(A[i]/x)%10);
	}
	for(i=0;i<10;i++)
	{
		int l=len_of_linkedlist(&table[i]);
		for(k=0;k<l-1;k++)                              
		{
			minimum=k;                            
			for(j=k+1;j<l;j++)                     
			{
				if(get_value_at_index(&table[i],j)<get_value_at_index(&table[i],minimum))   
				{
					minimum=j;		
				}
			}
			t=get_value_at_index(&table[i],minimum);
			change_value_at_index(&table[i],minimum,get_value_at_index(&table[i],k));
			change_value_at_index(&table[i],k,t);
		}
		for(k=index+1;k<index+l;k++)
		{
			A[k-1]=get_value_at_index(&table[i],k-index);
			// printf("%d ",get_value_at_index(&table[i],k-index));
		}
		index+=l-1;
	}
	for(i=0;i<10;i++)
	{
		print_list(&table[i]);
	}
	for(i=0;i<len;i++)
	{
		printf("%d ",A[i]);
	}
}