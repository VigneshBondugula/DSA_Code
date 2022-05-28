#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 2147483646
#define INT_MIN -2147483646

void print_arr(int A[], int n)
{
    for(int i=0; i<n ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int fill_zeroes(int n)
{
    int x=1;
    while(x<n)
    {
        x*=2;
    }
    return x;
}

int RMQ1(int A[],int ST[],int i,int j,int s,int e,int p,int n)
{
    if(j<s || i>e)
    {
        return n;
    }
    if(i<=s && e<=j)
    {
        return ST[p];
    }
    int m,l1,l2;
    m=(s+e)/2;
    l1=RMQ1(A,ST,i,j,s,m,2*p+1,n);
    l2=RMQ1(A,ST,i,j,m+1,e,2*p+2,n);
    if(A[l1]<A[l2]) return l1;
    else return l2;
}

int RMQ2(int A[],int ST[],int i,int j,int s,int e,int p,int n)
{
    if(j<s || i>e)
    {
        return n+1;
    }
    if(i<=s && e<=j)
    {
        return ST[p];
    }
    int m,l1,l2;
    m=(s+e)/2;
    l1=RMQ2(A,ST,i,j,s,m,2*p+1,n);
    l2=RMQ2(A,ST,i,j,m+1,e,2*p+2,n);
    if(A[l1]>A[l2]) return l1;
    else return l2;
}
void Build_min(int A[],int ST[],int n,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(i<n)
            ST[num+i-1]=i;
        else
            ST[num+i-1]=n;
    }
    for(i=num-2;i>-1;i--)
    {
        if(A[ST[2*i+1]]>A[ST[2*i+2]])
        {
            ST[i]=ST[2*i+2];
        }
        else
        {
            ST[i]=ST[2*i+1];
        }
    }
}

void Build_max(int A[],int ST[],int n,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(i<n)
            ST[num+i-1]=i;
        else
            ST[num+i-1]=n+1;
    }
    for(i=num-2;i>-1;i--)
    {
        if(A[ST[2*i+1]]<A[ST[2*i+2]])
        {
            ST[i]=ST[2*i+2];
        }
        else
        {
            ST[i]=ST[2*i+1];
        }
    }
}

void update_min(int ST[],int A[],int i,int x,int n)
{
    A[i]=x;
    i=(n+i-2)/2;
    while(i>0)
    {
        if(A[ST[2*i+1]]>A[ST[2*i+2]])
        {
            ST[i]=ST[2*i+2];
        }
        else
        {
            ST[i]=ST[2*i+1];
        }
        i=(i-1)/2;
    }
    if(A[ST[2*i+1]]>A[ST[2*i+2]])
    {
        ST[i]=ST[2*i+2];
    }
    else
    {
       ST[i]=ST[2*i+1];
    }
}

void update_max(int ST[],int A[],int i,int x,int n)
{
    A[i]=x;
    i=(n+i-2)/2;
    while(i>0)
    {
        if(A[ST[2*i+1]]<A[ST[2*i+2]])
        {
            ST[i]=ST[2*i+2];
        }
        else
        {
            ST[i]=ST[2*i+1];
        }
        i=(i-1)/2;
    }
    if(A[ST[2*i+1]]<A[ST[2*i+2]])
    {
        ST[i]=ST[2*i+2];
    }
    else
    {
       ST[i]=ST[2*i+1];
    }
}

int Find_min(int A[],int ST[],int X,int num,int n,int C)
{
    int y=A[X]-C;
    int i=num-1+X;
    int j=X;
    while(i>0)
    {
        int p=(i-1)/2;
        if(i==2*p+1)
        {
            if(A[ST[2*p+2]]<y)
            {
                i=2*p+2;
                break;
            }
        }
        i=p;
    }
    if(i==0)
    {
        j=n-1;
    }
    else
    {
        while(2*i+2 < 2*num-1)
        {
            if(A[ST[2*i+1]]<y) i=2*i+1;
            else i=2*i+2;
        }
        j=ST[i]-1;
    }
    return j;
}

int Find_max(int A[],int ST[],int X,int num,int n,int C)
{  
    int y=A[X]+C;
    int i=num-1+X;
    int j=X;
    while(i>0)
    {
        int p=(i-1)/2;
        if(i==2*p+1)
        {
            if(A[ST[2*p+2]]>y)
            {
                i=2*p+2;
                break;
            }
        }
        i=p;
    }
    if(i==0)
    {
        j=n-1;
    }
    else
    {
        while(2*i+2 < 2*num-1)
        {
            if(A[ST[2*i+1]]>y) i=2*i+1;
            else i=2*i+2;
        }
        j=ST[i]-1;
    }
    return j;
}


int query(int A[],int ST_min[],int ST_max[],int num,int N,int X,int C)
{
    int query1=Find_min(A,ST_min,X,num,N,C);
    int query2=Find_max(A,ST_max,X,num,N,C);
    int ans= query1>query2 ? query2:query1;
    return ans;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int num=fill_zeroes(N);
    int A[N+2];
    A[N]=INT_MAX;
    A[N+1]=INT_MIN;
    for(int i=0;i<N;i++)
    {
        scanf("%d ",&A[i]);
    }
    int ST_max[2*num-1];
    int ST_min[2*num-1];
    Build_min(A,ST_min,N,num);
    Build_max(A,ST_max,N,num);
    
    for(int i=0;i<M;i++)
    {
        char choice[2];
        int X,Y;
        scanf("%s %d %d",choice,&X,&Y);
        if(strcmp(choice,"U")==0)
        {
            update_max(ST_max,A,X-1,Y,num);
            update_min(ST_min,A,X-1,Y,num);
            // print_arr(A,N);
            // print_arr(ST_min,num);
            // print_arr(ST_max,num);

        }
        else if(strcmp(choice,"Q")==0)
        {
            if(Y>0)
            {
                int len=query(A,ST_min,ST_max,num,N,X-1,Y);
                int min=RMQ1(A,ST_min,X-1,len,0,num-1,0,N);
                int max=RMQ2(A,ST_max,X-1,len,0,num-1,0,N);
                int Z = (A[X-1]-A[min])>(A[max]-A[X-1]) ? (A[X-1]-A[min]):(A[max]-A[X-1]);
                printf("%d %d\n",len-(X-1)+1,Z);
            }
            else printf("-1 -1\n");
        }
    }

}