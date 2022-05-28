
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

int main()
{
    int i,n,oper,ind;
    scanf("%d",&n);
	scanf("%d",&o);
    int ST[2*n-1],A[n];
	for(i=0;i<n;i++)
	{
		A[i]=1;
	}
	Build(A,ST,n);
	for(i=0;i<o;i++)
	{
		scanf("%d %d",&oper,&ind);
        if(oper==0)
        {
            update(ST,A,ind,0,n);
        }
        else
        {
            
        }
	}
}