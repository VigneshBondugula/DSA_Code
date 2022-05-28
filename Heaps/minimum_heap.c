#include<stdio.h>
void bottom_up_heapify(int i,int H[])
{
    int p=(i-1)/2;
    int t;
    while(p>=0 && H[p]>H[i])
    {
        t=H[i];
        H[i]=H[p];
        H[p]=t;
        i=p;
        p=(i-1)/2;
    }
}
void top_down_heapify(int i,int H[],int n)
{
    int l,t;
    while(2*i+2<n)
    {
        if(H[2*i+1]<H[2*i+2]) l=2*i+1;
        else l=2*i+2;
        if(H[i]>H[l])
        {
            t=H[i];
            H[i]=H[l];
            H[l]=t;
        }
        else break;
    }
    if(2*i+1<n & H[i]>H[2*i+1])
    {
        t=H[i];
        H[i]=H[2*i+1];
        H[2*i+1]=t;
    }
}
void add(int H[],int n,int x)
{
    H[n++]=x;
    bottom_up_heapify(n-1,H);
}
void delete_min(int H[],int n)
{
    H[0]=H[--n];
    top_down_heapify(0,H,n);
}
void Build_heap(int n,int H[])
{
    for(int i=0;i<n;i++)
    {
        bottom_up_heapify(i,H);
    }
}
int main()
{
    int n=5;
    int H[100]={14,44,4,16,22};
    for(int i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }printf("\n");
    Build_heap(n,H);
    for(int i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }printf("\n");
    add(H,n,5);
    n++;
    for(int i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }printf("\n");
    delete_min(H,n);
    n--;
    for(int i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }printf("\n");
}