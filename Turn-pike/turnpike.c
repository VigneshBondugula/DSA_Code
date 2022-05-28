#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
    int data;
    int present;
    struct node* next;
};
void insert(struct node** head,int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=*head;
    newnode->data=value;
    newnode->next=NULL;
    newnode->present=1;
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
int check_for_n(int m)
{
    int n1,n2,n;
    n1=0.5+(sqrt(1+8*m))/2;
    n2=0.5-(sqrt(1+8*m))/2;
    n=n1>0?n1:n2;
    return n;    
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
int get_present_at_index(struct node** head,int index)
{
    struct node* temp=*head;
    for(int i=0;i<index;i++)
    {
        temp=temp->next;
    }
    return temp->present;
}
void change_present_at_index(struct node** head,int index,int value)
{
    struct node* temp=*head;
    for(int i=0;i<index;i++)
    {
        temp=temp->next;
    }
    temp->present=value;
}

int findmax(struct node** head)
{
    struct node* temp=*head;
    int max=0;
    while(temp!=NULL)
    {
        if((temp->data)>max  && temp->present==1)
        {
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}

int check(int S[],struct node** D,int val,int n,int m,int k[])
{
    int count=0,i;
    int Diff[n];
    for(i=0;i<n;i++)
    {
        Diff[i]=S[i]-val>0?S[i]-val:val-S[i];
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            k[j]=-1;
            if(get_present_at_index(D,j+1)==1)
            {
            // printf("%d   %d\n",Diff[i],get_value_at_index(D,j+1));
                if(get_value_at_index(D,j+1)==Diff[i])
                {
                    k[j]=j;
                    count++;
                    break;
                }
            }
        }
    }
    // for(i=0;i<m-1;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         k[i]=-1;
    //         printf("%d   %d\n",get_value_at_index(D,i+1),Diff[j]);
    //         if(get_present_at_index(D,i+1)==1)
    //         {
    //             if(get_value_at_index(D,i+1)==Diff[j])
    //             {
    //                 k[i]=i;
    //                 count++;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // printf("%d\n",count);
    if(count==n)
    {
         return 1;
    }
    return 0;

}
int turnpike(int S[],struct node** D,int m,int n,int x,int l,int r)
{
    int i,val,k[m],flag=0;
    val=findmax(D);
    printf("%d\n",val);
    if(check(S,D,val,n,m,k))
    {
        S[r]=val;
        for(int i=0;i<m-1;i++)
        {
            if(k[i]!=-1)
            {
                 change_present_at_index(D,i+1,0);
            }
        }
        flag=turnpike(S,D,m,n,x+1,l,r-1);
        if(flag!=1)
        {
        for(int i=0;i<m-1;i++)
        {
            if(k[i]!=-1)
            {
                 change_present_at_index(D,i+1,1);
            }
        }
        }
    }
    if(check(S,D,S[n-1]-val,n,m,k) && flag==0)
    {
        S[l]=S[n-1]-val;
        for(int i=0;i<m-1;i++)
        {
            if(k[i]!=-1)
            {
                 change_present_at_index(D,i+1,0);
            }
        }
        if(flag!=1)
        {
        for(int i=0;i<m-1;i++)
        {
            if(k[i]!=-1)
            {
                 change_present_at_index(D,i+1,1);
            }
        }
        }
    }
    return flag;
}
int main()
{
    int m,i=0,n,num,l,r;
    struct node* D=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&m);

    //Input
    for(i=0;i<m-1;i++)
    {
        scanf("%d ",&num);
        insert(&D,num);
    }scanf("%d",&num);
    insert(&D,num);
    // print_list(&D);

    //Finding n
    n=check_for_n(m);
    // printf("%d\n",n);

    int S[n];
    for(i=0;i<n;i++)
    {
        S[i]=0;
    }
    S[n-1]=get_value_at_index(&D,m);
    // printf("%d",get_value_at_index(&D,m));
    change_present_at_index(&D,n-1,0);
    turnpike(S,&D,m,n,0,0,n-2);
    for(i=0;i<n;i++)
    {
        printf("%d",S[i]);
    }
    
}