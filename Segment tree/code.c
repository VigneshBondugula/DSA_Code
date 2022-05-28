#include<stdio.h>
void Build(int A[],int ST[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ST[n+i-1]=i;
    }
    for(i=n-2;i>-1;i--)
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
void print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void update(int ST[],int A[],int i,int x,int n)
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
int RMQ1(int A[],int ST[],int i,int j,int s,int e,int p)
{
    if(j<s || i>e)
    {
        return 8;
    }
    if(i<=s && e<=j)
    {
        return ST[p];
    }
    int m,l1,l2;
    m=(s+e)/2;
    l1=RMQ1(A,ST,i,j,s,m,2*p+1);
    l2=RMQ1(A,ST,i,j,m+1,e,2*p+2);
    if(A[l1]<A[l2]) return l1;
    else return l2;
}
int next_right_min(int A[],int ST[],int i,int n)
{
    int p=0,s=0,e=n-1,j=n,m;
    while(p<n-1)
    {
        m=(s+e)/2;
        if(i<=m)
        {
            if(A[ST[2*p+2]]<A[i]) j=2*p+2;
            p=2*p+1;
            e=m;
        }
        else
        {
            p=2*p+2;
            s=m+1;
        }
    }
    while(j<n-1)
    {
        if(A[ST[2*j+1]]<A[i])
        {
            j=2*j+1;
        }
        else j=2*j+2;
    }
    return ST[j];
}
int last_min(int A[],int ST[],int i,int n)
{
    int p=0;
    while(p<n-1)
    {
        if(A[ST[2*p+2]]<=A[i])
        {
            p=2*p+2;
        }
        else
        {
            p=2*p+1;
        }
    }
    return ST[p];
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int A[n],ST[2*n-1];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    Build(A,ST,n);
    print_arr(A,n);
    printf("\n");
    print_arr(ST,2*n-1);
    update(ST,A,2,0,n);
    printf("\n");
    print_arr(A,n);
    printf("\n");
    print_arr(ST,2*n-1);
    printf("\n");
    printf("%d",RMQ1(A,ST,0,2,0,n-1,0));
    printf("\n%d",next_right_min(A,ST,2,n));
    printf("\n%d",last_min(A,ST,1,n));
}