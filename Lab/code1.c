#include<stdio.h>
void bottom_up_heapify(int i,int H[])
{
    int p=(i-1)/2;
    int t;
    while(p>=0 && H[p]<H[i])
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
        if(H[2*i+1]>H[2*i+2]) l=2*i+1;
        else l=2*i+2;
        if(H[i]<H[l])
        {
            t=H[i];
            H[i]=H[l];
            H[l]=t;
        }
        else break;
    }
    if(2*i+1<n & H[i]<H[2*i+1])
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
int delete_max(int H[],int n)
{
    int t=H[0];
    H[0]=H[--n];
    top_down_heapify(0,H,n);
    return t;
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
    int n=6;
    int H[100]={2,7,4,1,8,1};
    int t1,t2;
    for(int i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }printf("\n");
    Build_heap(n,H);
    while(n>1)
    {
        t1=delete_max(H,n);
        n--;
        t2=delete_max(H,n);
        n--;
        add(H,n,t1-t2);
        n++;
    }
    printf("%d",H[0]);
}