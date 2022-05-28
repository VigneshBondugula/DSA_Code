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

    int P[len+1];
    P[0]=0;
    for(i=1;i<len+1;i++)
    {
        P[i]=a[i-1]+P[i-1];
    }
    // for(i=0;i<len+1;i++)
    // {
    //     printf("%d ",P[i]);
    // }printf("\n");

    i=0;
    for(j=1;j<len+1;j++)
    {
        if(P[j]-P[i]>max)
        {
            max=P[j]-P[i];
        }
        if(P[j]<P[i])
        {
            i=j;
        }
    }
    printf("%d",max);
}