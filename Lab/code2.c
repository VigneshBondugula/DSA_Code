#include<stdio.h>
int main()
{
    int label;
    scanf("%d",&label);
    int n=1,l=0;
    while(n<label)
    {
        n*=2;
        l++;
    }n=n/2;
    int arr[l];
    int len=l;
    arr[--l]=label;
    while(l>0)
    {
        arr[l-1]=(3*n-1-label)/2;
        label=arr[l-1];
        l--;
        n/=2;  
    }
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}