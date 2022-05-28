#include<stdio.h>
#include<stdlib.h>
void IN(int A[],int i,int x,int n)
{
    while(i<=n)
    {
        A[i]+=x;
        i+=i&(-i);
    }
}
void PS(int A[],int i)
{
    int s=0;
    while(i>0)
    {
        s+=A[i];
        i-=i&(-i);
    }
}
void Build(int A[],int BIT[],int n)
{
    for(int i=1;i<n;i++)
    {
        IN(BIT,i,A[i],n);
    }
}
int main()
{
    int n=10;
    int A[10]={0,4,3,2,-1,-2,6,-2,7,4};
    int BIT[n];
    for(int i=0;i<n;i++)
    {
        BIT[i]=0;
    }
    Build(A,BIT,n);
    for(int i=0;i<n;i++)
    {
        printf("%d",BIT[i]);
    }
}