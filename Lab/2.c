#include<stdio.h>
int BS(int T[],int P[],int i,int l,int r,int S)
{
    int m=(l+r)/2;
    static int max=0;
    printf("%d  %d\n",l,r);
    printf("%d\n",max);
    if(l>r)
    {
        return max;
    }
    else if(P[m]-P[i]<S)
    {
        if(P[m]-P[i]>max)
        {
            max=P[m]-P[i];
        }
        BS(T,P,i,m+1,r,S);
    }
    else
    {
        BS(T,P,i,l,m-1,S);
    }
}
int main()
{
    int N,S,i,j,temp;
    int min=0;
    scanf("%d %d",&N,&S);
    int T[N],D[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&T[i],&D[i]);
    }
    int P[N];
    P[0]=0;
    for(i=1;i<N;i++)
    {
        P[i]=P[i-1]+(T[i]-T[i-1])*D[i-1];
    }

    for(i=0;i<N;i++)
    {
        temp=BS(T,P,i,i,N,S);
        printf("%d",temp);
        if(temp<min)
        {
            min=temp;
        }
    }
    printf("%d",min);
}