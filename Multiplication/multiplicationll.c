#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100000
struct node{
    int data;
    struct node* next;
};
 void add_at_beg(struct node** head,int value)
 {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=*head;
    *head=newnode;
 }
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
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void change_at_index(struct node** head,int index,int value)
{
    struct node* temp=*head;
    for(int i=0;i<index;i++)
    {
        temp=temp->next;
    }
    temp->data=value;
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

int main()
{
	char n;
	int num,c=0,d=0;
	long int k=0,len1=0,len2=0,i=0,j;
	FILE* fp;
	fp=fopen("num1","r");
    struct node* num1=(struct node*)malloc(sizeof(struct node));
    struct node* num2=(struct node*)malloc(sizeof(struct node));
    struct node* product=(struct node*)malloc(sizeof(struct node));    
	while((n=fgetc(fp))!=EOF)
	{
        num=(int)n-'0';
        insert(&num1,num);
		len1++;
	}
	fclose(fp);
    i=0;
    fp=fopen("num2","r");
	while((n=fgetc(fp))!=EOF)
	{
        num=(int)n-'0';
        insert(&num2,num);
		len2++;
	}
	fclose(fp);
    for(i=0;i<len1*len2;i++)
    {
        insert(&product,0);
    }
    print_list(&num1);
    print_list(&num2);

    for(i=0;i<len2;i++)
	{
        for(j=0;j<len1;j++)
        {
            // printf("%d",get_value_at_index(&num1,len1-j)*get_value_at_index(&num2,len2-i));
		    c=c+(get_value_at_index(&num1,len1-j)*get_value_at_index(&num2,len2-i));
            d=d+get_value_at_index(&product,len1*len2-j-i)+c%10;
	        change_at_index(&product,len1*len2-j-i,d%10);
            d=d/10;
		    c=c/10;
        }
	}
	change_at_index(&product,len1*len2-j-i,c);
    print_list(&product);
}