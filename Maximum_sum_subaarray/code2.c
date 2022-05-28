#include<stdio.h>
int main()
{
    char n;
	int num,c=0,len=0;
    int i=0,j=0,max=0;
    scanf("%d",&len);
    int a[len];
    for(i=0;i<len-1;i++)
    {
        scanf("%d ",&a[i]);
    }scanf("%d",&a[i]);

    i=0;
    int sum=0;
    for(j=0;j<len;j++)
    {
        sum=sum+a[j];
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
            i=j;
        }
    }
    printf("%d",max);
}