#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int Abs(int n)
{
    if(n<0)
    {
        return -n;
    }
    return n;
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

void delete(struct node** head,int value)
{
    struct node* temp=*head;
    struct node* temp2=NULL;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            temp2->next=temp->next;
            free(temp);
            return;
        }
        temp2=temp;
        temp=temp->next;
    }
}

int findmax(struct node** head)
{
    struct node* temp=*head;
    int max=0;
    while(temp!=NULL)
    {
        if((temp->data)>max)
        {
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}

int check_for_n(int m)
{
    int n1,n2,n;
    n1=0.5+(sqrt(1+8*m))/2;
    n2=0.5-(sqrt(1+8*m))/2;
    n=n1>0?n1:n2;
    return n;    
}

int Search(struct node** head,int value)
{
    struct node* temp=*head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int Possible(int S[],struct node** D,int max,int n,int l,int r)
{
    int i;
    for(i=0;i<l;i++)
    {
        if(!Search(D,Abs(S[i]-max)))
        {
            return 0;
        }
    }
    for(i=r+1;i<n;i++)
    {
        if(!Search(D,Abs(S[i]-max)))
        {
            return 0;
        }
    }
    return 1;
}

int Try(int S[],struct node** D,int n,int l,int r)
{
    int found=0,i;
    if(*D==NULL)
    {
        return 1;
    }
    int max=findmax(D);
    if(Possible(S,D,max,n,l,r))
    {
        S[r]=max;
        for(i=0;i<l;i++)
        {
            delete(D,Abs(S[i]-S[r]));
        }
        for(i=r+1;i<n;i++)
        {
            delete(D,Abs(S[i]-S[r]));
        }
        found=Try(S,D,n,l,r-1);
        if(found==0)
        {
            for(i=0;i<l;i++)
            {
                insert(D,Abs(S[i]-S[r]));
            }
            for(i=r+1;i<n;i++)
            {
                insert(D,Abs(S[i]-S[r]));
            }
        }
    }
    if(Possible(S,D,S[n-1]-max,n,l,r) && found==0)
    {
        S[l]=S[n-1]-max;
        for(i=0;i<l;i++)
        {
            delete(D,Abs(S[i]-S[l]));
        }
        for(i=r+1;i<n;i++)
        {
            delete(D,Abs(S[i]-S[l]));
        }
        found=Try(S,D,n,l+1,r);
        if(found==0)
        {
            for(i=0;i<l;i++)
            {
                insert(D,Abs(S[i]-S[l]));
            }
            for(i=r+1;i<n;i++)
            {
                insert(D,Abs(S[i]-S[l]));
            }
        }
    }
    return found;
}

int turnpike(int S[],struct node** D,int n)
{
    int i;
    S[0]=0;
    S[n-1]=findmax(D);
    delete(D,findmax(D));
    S[n-2]=findmax(D);
    delete(D,findmax(D));
    if(Search(D,S[n-1]-S[n-2]))
    {
        delete(D,S[n-1]-S[n-2]);
        return Try(S,D,n,1,n-3);
    }
    else{
        return 0;
    }
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

    //Finding n
    n=check_for_n(m);

    int S[n];
    turnpike(S,&D,n);
        for(i=0;i<n;i++)
        {
            printf("%d  ",S[i]);
        }
}