#include<stdio.h>
#include<stdlib.h>
// #define swap(a,b) int t=0;t=a;a=b;b=t;
void swap(int A[],int a,int b)
{
    int t;
    t=A[a];
    A[a]=A[b];
    A[b]=t;
}
int partition(int A[],int i,int j,int pivot)
{
    int l=i,r=j;
    while(l<=r)
    {
        while(l<=r && A[l]<=pivot)
        {l++;}
        while(l<=r && A[r]>pivot)
        {r--;}
        if(l<=r)
        {
            swap(A,l,r);
            l++;
            r--;
        }
    }
    int k=l-1;
    A[i-1]=A[k];
    A[k]=pivot;
    return k;
}
int RFindrank(int A[],int i,int j,int r)
{
    int k,p;
    if(i<j)
    {
        p=(rand()%(j-i+1))+i;
        swap(A,i,p);
        k=partition(A,i+1,j,A[i]);
        printf("%d %d\n",p,k);
        // for(int i=0;i<j;i++)
        // {
        //     printf("%d  ",A[i]);
        // }printf("\n");
        if(r==j-k+1)
        {
            return k;
        }
        else if(r<j-k+1)
        {
            RFindrank(A,k+1,j,r);
        }
        else
        {
            RFindrank(A,i,k-1,r-(j-k+1));
        }
    }
}
int main()
{
    int i,n,r;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&A[i]);
    }scanf("%d",&A[i]);
    scanf("%d",&r);
    printf("%d",A[RFindrank(A,0,n,r)-1]);
}